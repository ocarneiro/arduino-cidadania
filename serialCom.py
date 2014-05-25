import serial;

porta = "COM3";
velocidade = 9600;

with serial.Serial(porta, velocidade) as conexao:

  estado = '0';

  while estado == '0' or estado == '1' or estado == '23' :
    estado = raw_input(" 1 acende \n 0 apaga \n 2 desliga \n");
    print 'estado = ', estado;
    # 0 e 1 vao para o arduino
    if (estado >= '0' and estado <= '100'):
        print 'enviando ', estado;
        conexao.write(estado);
        leitura_serial = conexao.readline();
        print "Resposta = ", leitura_serial, "\n";
    # 2 encerra
    if (estado == '2'):
        print 'ok, terminando';
        break;
  print "Saindo"
conexao.close();


