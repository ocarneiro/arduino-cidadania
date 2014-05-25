import serial
import time

############################
def num(s):
    try:
        retorno = int(s)
        if retorno > 100 : return 100
        if retorno < 0 : return 0
        return int(s)
    except ValueError:
        return 0
    
############################
porta = "COM3"
velocidade = 9600
debug = True

#with serial.Serial(porta, velocidade) as conexao:

estado = 0
time.sleep(1)

while estado >= 0 and estado <= 100 :
    if debug: print 'Enviando ', estado
    #conexao.write(estado)
    time.sleep(1) #espera o envio e a resposta
    if debug: print 'Recebendo resposta'
    leitura_serial = 'Mock ' + str(estado) #leitura_serial = conexao.readline()
    if debug: print "Resposta = ", leitura_serial, "\n"
    
    entrada = raw_input("Entre um valor entre 0 e 100. Para sair, entre q\n")
    if entrada == 'q' : break
    estado = num(entrada)

    if debug : 
        print bytearray(entrada)[0]
        #for ba in bytearray(entrada):
            #print "ba = " + str(ba)
    
print "Saindo"
#conexao.close()

