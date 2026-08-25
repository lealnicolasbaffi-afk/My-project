from Parser import parser
from pathlib import Path
import argparse


config = argparse.ArgumentParser()
config.add_argument('--caminho_dos_testes', type=str, default='pasta_com_testes')
config.add_argument('--prompt', type=str, default='instrucao.tex')

args = config.parse_args()
caminho_testes = args.caminho_dos_testes
prompt= args.prompt


def read_tests(pasta):
    #pega o caminho da pasta
    pasta = Path(pasta)
    for arquivo in pasta.iterdir():
        # verifica se o arquivo está em formato .tex
        if arquivo.is_file() and arquivo.suffix == '.tex':
            score = parser(str(arquivo), prompt) 

            #salva a comparação
            with open("results.tex", 'a', encoding='utf-8') as save:
                save.write(f"Grade: {score:.2f}%")
        
if __name__ == "__main__":
    # limpa o arquivo de resultados antes de começar
    with open("answer_key.tex", 'w', encoding='utf-8') as initial:
        initial.write("Gabarito: \n")
    with open("results.tex", 'w', encoding='utf-8') as something:
        pass
    
    read_tests(caminho_testes)