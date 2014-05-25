import serial
import time

porta = "COM3"
velocidade = 9600
debug = True

with serial.Serial(porta, velocidade) as conexao:

  estado = '0'
  time.sleep(2)

  while estado >= '0' and estado <= '100' :
    if debug: print 'Enviando ', estado
    conexao.write(estado)
    time.sleep(2) #espera o envio e a resposta
    if debug: print 'Recebendo resposta'
    leitura_serial = conexao.readline()
    print "Resposta = ", leitura_serial, "\n"
    estado = raw_input(" 1 acende \n 0 apaga \n 2 desliga \n")
  print "Saindo"
conexao.close()


