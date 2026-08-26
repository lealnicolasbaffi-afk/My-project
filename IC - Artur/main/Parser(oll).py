import random
import regex as re
import ollama

# =====================================================================
# COMO MUDAR O MODELO:
# Altere o valor dessa variável para o nome do modelo desejado.
# Exemplos: "llama3.2", "mistral", "gemma2", "phi3", "qwen2.5"
MODELO_OLLAMA = "llama3.2"
# =====================================================================

def conf_modelo():
    # O Ollama carrega o modelo na memória no momento do envio da requisição,
    # descartando a necessidade de inicializar um cliente global.
    pass

def ler_arquivo(caminho_arquivo):
    extensao = caminho_arquivo.split('.')[-1].lower()
    
    if extensao == 'tex':
        with open(caminho_arquivo, 'r', encoding='utf-8') as arquivo:
            return arquivo.read()
    else:
        print(f"Formato de arquivo {extensao} não suportado.")
        return ""

def extract_questions(text):
    extracted = []
    last_question = 0

    for choices in re.finditer(r'\\begin{choices}.*?\\end{choices}', text, re.DOTALL):
        choices_block = choices.group()
        statement = text[last_question:choices.start()].strip()
        extracted.append((statement, choices_block))
        last_question = choices.end()
        
    return extracted

def extract_string_choice(choices_block):
    choices = []
    correct = []

    pattern = r'\\(correctchoice|wrongchoice)\{'

    for match in re.finditer(pattern, choices_block):
        kind = match.group(1)
        start = match.end()

        depth = 1
        i = start

        while i < len(choices_block) and depth > 0:
            if choices_block[i] == "{":
                depth += 1
            elif choices_block[i] == "}":
                depth -= 1
            i += 1

        text = choices_block[start:i-1].strip()
        choices.append(text)

        if kind == "correctchoice":
            correct.append(text)
    return choices, correct
    
def shuffle_and_format(statement, choices, correct):
    random.shuffle(choices)

    letters = "abcdefghijklmnopqrstuvwxyz"
    text = statement + "\n\n"
    gabarito_comparacao = []
    salva_gabarito = []

    for i, c in enumerate(choices):
        text += f"{letters[i]}) {c}\n"

        if c in correct:
            gabarito_comparacao.append(f"{letters[i]})")
            salva_gabarito.append(f"{letters[i]}) {c}")
            
    return text, choices, gabarito_comparacao, salva_gabarito

def save_choice(labeled_correct_choices):
    with open("answer_key.tex", "a", encoding="utf-8") as arquivo:
        for i, q in enumerate(labeled_correct_choices):
            arquivo.write(f"Questão {i+1}: " + "\n ".join(q) + "\n")

def restructure_tex(text):
    questions = extract_questions(text)
    formatted_questions = []
    gabarito_letras = []
    gabarito_final = []

    for i, (statement, choices_block) in enumerate(questions):
        choices, correct = extract_string_choice(choices_block)
        question_text, choices, gabarito_comparacao, salva_gabarito = shuffle_and_format(statement, choices, correct)
        formatted_questions.append(f"Questão {i+1}\n\n{question_text}")
        gabarito_letras.append(gabarito_comparacao)
        gabarito_final.append(salva_gabarito)
        
    return formatted_questions, gabarito_letras, gabarito_final

def LLM_getAnswer(input_text):
    # Executa a inferência diretamente no serviço local do Ollama
    response = ollama.chat(
        model=MODELO_OLLAMA,
        messages=[
            {"role": "user", "content": input_text}
        ],
        options={
            "temperature": 0.1
        }
    )
    return response['message']['content']

def compare_answer(correct, string_answer):
    answers = []
    for line in string_answer.splitlines():
        alternativas = re.findall(r'(?<!\w)([a-z]\))', line)        
        if alternativas:
            answers.append(alternativas)

    pontuacao = 0
    
    for i, (gab, resp) in enumerate(zip(correct, answers)):
        set_gab = set(gab)
        set_resp = set(resp)
        right_answers = len(set_gab & set_resp)
        total = len(set_gab)
        
        pontuacao += right_answers / total

        with open("results.tex", "a", encoding="utf-8") as arquivo:
            arquivo.write(f"Questão {i + 1}: {right_answers}/{total} - {', '.join((set_resp))}\n")

    return (pontuacao / len(correct)) * 100

def parser(test, instrucao):
    conf_modelo()
    formatted_questions, gabarito_comparacao, gabarito_final = restructure_tex(ler_arquivo(test))
    save_choice(gabarito_final)    
    input_text = ler_arquivo(instrucao) + "\n\n" + "\n\n".join(formatted_questions)
    resposta = LLM_getAnswer(input_text)
    print(resposta)
    
    return compare_answer(gabarito_comparacao, resposta)