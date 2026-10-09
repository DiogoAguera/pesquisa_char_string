  #include <Arduino.h>
  #include <string.h>//*strlen, strcpy, strcat, strcmp, strchr
  #include <stdlib.h>//* atoi


  void textoChar();
  void textoString();



  void setup() 
  {
    Serial.begin(9600);
    Serial.println("");
    Serial.println("============================================================================");
    textoChar();
    textoString();

  }

  void loop() {}

  void textoChar()
  {
    //! Todo vetor de caracter cria o ultimo caraccter como null para indicar que o texto acabou
    //* Texto literal
    //* Use const char* quando o texto nao sera alterado
    //* o * serve para criar um ponteiro, ele imprime a partir daquele endereco ate achar \0, usando [] voce cria um vetor
    const char  cidade[] = "Sao Paulo" ;   // * indica que nao esta trabalhando com uma posicao fixa 
    Serial.println(cidade);

    //* Descobrindo o tamanho do texto
    //* strlen conta quantos caracteres antes do '/0'  
    int tamanhoDoTextoCidade = strlen(cidade);
    Serial.print("Comprimento do texto: ");
    Serial.println(tamanhoDoTextoCidade);

    //* Descobrindo o tamanho ocupado
    //* O tamanho da string vai constar 9, mas na realidade sao 10 por conta do ultimo caracter que e o null
    //* o sizeoff() retornara um byte a mais que o comprimento por causa do '/0'
    int tamanhoVariavelCidade = sizeof(cidade);
    Serial.print("Espaco utilizado: ");
    Serial.println(tamanhoVariavelCidade);

    //* Se nao tiver o \0 ele vai imprimir coisas da memoria ate achar um \0
    //* O caractere \0 e colocado automaticamente quando escrevemos um texto entre " "
    char vetorTexto[7] = {'T', 'h', 'i', 'a', 'g', 'o', '\0'}; 
    Serial.println(vetorTexto);

    //* Comparar texto
    const char* cidade1 = "Sao Caetano";
    const char* cidade2 = "Sao Caetano ";

    if(strcmp(cidade1, cidade2) == 0)
      Serial.println("Os textos sao iguais ");

    else
      Serial.println("Os textos sao diferentes ");
    
    //* strcmp analiza a ordem lexia das palavras, se a primeira palavra vem antes 
    //* que a segunda o valor retornado sera menor que zero, se a primeira palavra 
    //* vem apos a segundao retorno sera maior que zero 


    //! =========================
    //! TEXTO EDITAVEL COM char[]
    //! =========================
    
    char nomeAluno[20] = "Diego";
    Serial.println(nomeAluno);

    //* Alterando caracteres individualmente
    nomeAluno[2] = 'o';
    Serial.println(nomeAluno);

    //* Copiado o texto para dentro do vetor 
    //! Cuidado: o vetor precisa ter espaco suficiente 

    strcpy(nomeAluno, "Felipe");
    Serial.println(nomeAluno);

    //* Contatenando de textp ap final
    char frase[40] = "Ola";
    strcat(frase, " Mundo! ");
    Serial.println(frase);

    //* Procurando um caractere no texto
    //* Frase "Ola Mundo" 
    //* Ele vai procurar a letra, achar o endereco, e imprimir tudo ate achar o \0
    char* posicaoLetra = strchr(frase, 'M');

    if(posicaoLetra != NULL)
    {
      Serial.println("Letra encontrada");
      Serial.println(posicaoLetra);
    }
    else
    {
      Serial.println("Letra nao encontrada");
    }

    //* Convertendo texto numerico para inteiro 
    char idadeTexto[] = "45"; // 52, 53, \0
    int idade = atoi(idadeTexto);
    Serial.println(idade);
    //TODO fazer uma funcao com for pra transformar texto em idade

    //*=============================================
    //* USANDO char* APONTANDO PARA UM VETOR DE char
    //TODO estudar ponteiro (recomendavel)
    //*=============================================

    //* Aqui temos um vetor editavel
    char textoEditavel[30] = "robotica";

    //! professor nao trabalhou ponteiro, estudar por fora 

    Serial.println("============================================================================");
  }

  void textoString()
  {
    
    //*=============================================
    //* USANDO String 
    //* String e uma classe 
    //*=============================================
    
    String nome = "Diogo";
    String curso = "Desenvolvimento de sistemas";
    String mensagem = "Ola"; 

    //* Contatenando String 
    mensagem = mensagem + ", " + nome + "! Bem vindo ao curso de: " + curso +".";
    Serial.println(mensagem);

    //* Tamanho da String 
    int tamanhoMensagem = mensagem.length();
    Serial.print("Tamanho String em letra(s): ");
    Serial.println(tamanhoMensagem);

    //* Acessando um caractere em uma posicao especifica 
    char primeiraLetra = mensagem.charAt(0);
    Serial.print("Primeira Letra: ");
    Serial.println(primeiraLetra);

    //* Tambem e possivel acessar com colchetes
    char segunadLetra = mensagem[1];
    Serial.println(segunadLetra);

    //*Procurando um texto ddentro da String
    int posicaoTextoProcurado = mensagem.indexOf("curso");
    Serial.println(posicaoTextoProcurado);

    //* Extraindo um texto dentro da String ]
    int inicioNomeCurso = posicaoTextoProcurado + 9; //* posicao da palavra curso + nove caracteres 
    Serial.println(mensagem.substring(inicioNomeCurso, tamanhoMensagem - 1)); //* -1 tira o ponto final

    //* Substituindo um trexo dentro da String
    mensagem.replace("Ola, ", "Oi, tudo bom?");
    Serial.println(mensagem);

    //* Convertendo para maiusculas
    mensagem.toUpperCase();
    Serial.println(mensagem);

    //* Convertendo tudo para minusculas
    mensagem.toLowerCase();
    Serial.println(mensagem);

    //* Convertendo texto numerico para inteiro
    String textoNumero = "123";
    int numero = textoNumero.toInt();
    Serial.println(numero * 2);

    //* Verificando se a String esta vazia
    String textoVaizo = "";
    if(textoVaizo.length() == 0) Serial.println("O texto esta vazio");

    //* Converntendo String para const char*
    //* Isso e util quando alguma biblioteca espera texto estilo C (char)
    const char* textoComoChar = mensagem.c_str();
    Serial.println(textoComoChar);



  }