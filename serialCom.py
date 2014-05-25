import serial;

porta = "COM3";
velocidade = 9600;

with serial.Serial(porta, velocidade) as conexao:

  estado = '0';

  while estado >= '0' and estado <= '100' :
    print 'Enviando ', estado;
    conexao.write(estado);
    leitura_serial = conexao.readline();
    print "Resposta = ", leitura_serial, "\n";
    estado = raw_input(" 1 acende \n 0 apaga \n 2 desliga \n");
  print "Saindo"
conexao.close();


