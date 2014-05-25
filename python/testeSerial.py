import serial
import time

porta = "COM3"
velocidade = 9600
debug = True

with serial.Serial(porta, velocidade) as conexao:

  envio = raw_input("0 a 100")
  #envio_num = int(envio)
  time.sleep(1)
  print "Enviando = ", envio, "\n"
  conexao.write(envio)
  conexao.write('\n')
  time.sleep(1)
  leitura_serial = conexao.readline()
  print "Resposta = ", leitura_serial, "\n"
  
conexao.close()
