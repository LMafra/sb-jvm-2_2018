/**
 * @brief Nao faz nada
 * 
 */
void print_jvm_nop();

/**
 * @brief Empilha um null na pilha
 * 
 */
void print_jvm_aconst_null();

/**
 * @brief Todos iconst empilham um int que eh uma constante na pilha
 * 
 */
void print_jvm_iconst_m1();
void print_jvm_iconst_0();
void print_jvm_iconst_1();
void print_jvm_iconst_2();
void print_jvm_iconst_3();
void print_jvm_iconst_4();
void print_jvm_iconst_5();
/**
 * @brief Todos lconst empilham um long int que é constante na pilha
 * 
 */
void print_jvm_lconst_0();
void print_jvm_lconst_1();

/**
 * @brief Todos fconst empilha um float na pilha
 * 
 */
void print_jvm_fconst_0();
void print_jvm_fconst_1();
void print_jvm_fconst_2();

/**
 * @brief Todos dconst empilham um double na pilha
 * 
 */
void print_jvm_dconst_0();
void print_jvm_dconst_1();

/**
 * @brief Empilha um byte na pilha
 * 
 */
void print_jvm_bipush();

/**
 * @brief Empilha um short na pilha
 * 
 */
void print_jvm_sipush();

/**
 * @brief Empilha um item da constant pool na pilha
 * 
 */
void print_jvm_ldc();

/**
 * @brief Empilha um item da constant pool de wind index na pilha
 * 
 */
void print_jvm_ldc_w();

/**
 * @brief Empilha um long ou um double da constant pool na pilha
 * 
 */
void print_jvm_ldc2_w();

/**
 * @brief Carrega um int de uma variavel local
 * 
 */
void print_jvm_iload();

/**
 * @brief Carrega um long de uma variavel local
 * 
 */
void print_jvm_lload();

/**
 * @brief Carrega um float de uma variavel local
 * 
 */
void print_jvm_fload();

/**
 * @brief Carrega um double de uma variavel local
 * 
 */
void print_jvm_dload();

/**
 * @brief Carrega uma referencia de uma variavel local
 * 
 */
void print_jvm_aload();

/**
 * @brief Todos iloads<n> carregam um int de uma variavel local
 * 
 */
void print_jvm_iload_0();
void print_jvm_iload_1();
void print_jvm_iload_2();
void print_jvm_iload_3();

/**
 * @brief Todos floads<n> carregam um long de uma variavel local
 * 
 */
void print_jvm_lload_0();
void print_jvm_lload_1();
void print_jvm_lload_2();
void print_jvm_lload_3();

/**
 * @brief Todos floads<n> carregam um float de uma variavel local
 * 
 */
void print_jvm_fload_0();
void print_jvm_fload_1();
void print_jvm_fload_2();
void print_jvm_fload_3();

/**
 * @brief Todos dloads<n> carregam um double de uma variavel local
 * 
 */
void print_jvm_dload_0();
void print_jvm_dload_1();
void print_jvm_dload_2();
void print_jvm_dload_3();

/**
 * @brief Todos aloads<n> carregam uma referencia de uma variavel local
 * 
 */
void print_jvm_aload_0();
void print_jvm_aload_1();
void print_jvm_aload_2();
void print_jvm_aload_3();

/**
 * @brief Carrega um int de um vetor
 * 
 */
void print_jvm_iaload();

/**
 * @brief Carrega um float de um vetor
 * 
 */
void print_jvm_faload();

/**
 * @brief Carrega um double de um vetor
 * 
 */
void print_jvm_daload();

/**
 * @brief Carrega uma referencia de um vetor
 * 
 */
void print_jvm_aaload();

/**
 * @brief Carrega um byte ou um boolean de um vetor
 * 
 */
void print_jvm_baload();

/**
 * @brief Carrega um char de um vetor
 * 
 */
void print_jvm_caload();

/**
 * @brief Carrega um short de um vetor
 * 
 */
void print_jvm_saload();

/**
 * @brief Armazena um int em uma variavel local
 * 
 */
void print_jvm_istore();

/**
 * @brief Armazena um long em uma variavel local
 * 
 */
void print_jvm_lstore();

/**
 * @brief Armazena um float em uma variavel local
 * 
 */
void print_jvm_fstore();

/**
 * @brief Armazena um double em uma variavel local
 * 
 */
void print_jvm_dstore();

/**
 * @brief Armazena uma referencia em uma variavel local
 * 
 */
void print_jvm_astore();

/**
 * @brief Todos os istore_<n> armazenam um int numa variavel local
 * 
 */
void print_jvm_istore_0();
void print_jvm_istore_1();
void print_jvm_istore_2();
void print_jvm_istore_3();

/**
 * @brief Todos os lstore_<n> armazenam um long numa variavel local
 * 
 */
void print_jvm_lstore_0();
void print_jvm_lstore_1();
void print_jvm_lstore_2();
void print_jvm_lstore_3();

/**
 * @brief Todos os fstore_<n> armazenam um float numa variavel local
 * 
 */
void print_jvm_fstore_0();
void print_jvm_fstore_1();
void print_jvm_fstore_2();
void print_jvm_fstore_3();

/**
 * @brief Todos os dstore_<n> armazenam um double numa variavel local
 * 
 */
void print_jvm_dstore_0();
void print_jvm_dstore_1();
void print_jvm_dstore_2();
void print_jvm_dstore_3();

/**
 * @brief Todos os astore_<n> armazenam uma referencia numa variavel local
 * 
 */
void print_jvm_astore_0();
void print_jvm_astore_1();
void print_jvm_astore_2();
void print_jvm_astore_3();

/**
 * @brief Armazena num vetor de inteiros
 * 
 */
void print_jvm_iastore();

/**
 * @brief Armazena num vetor de long
 * 
 */
void print_jvm_lastore();

/**
 * @brief Armazena num vetor de float
 * 
 */
void print_jvm_fastore();

/**
 * @brief Armazena num vetor de double
 * 
 */
void print_jvm_dastore();

/**
 * @brief Armazena num vetor de referencias
 * 
 */
void print_jvm_aastore();

/**
 * @brief Armazena num vetor de byte ou booleans
 * 
 */
void print_jvm_bastore();

/**
 * @brief Armazena num vetor de char
 * 
 */
void print_jvm_castore();

/**
 * @brief Armazena num vetor de short
 * 
 */
void print_jvm_sastore();

/**
 * @brief Desempilha um valor da pilha de operandos
 * 
 */
void print_jvm_pop();

/**
 * @brief Desempilha um ou dois valores da pilha de operandos
 * 
 */
void print_jvm_pop2();

/**
 * @brief Duplica o operando no topo da pilha
 * 
 */
void print_jvm_dup();

/**
 * @brief Duplica o operando no topo da pilha e insere dois valores a baixo
 * 
 */
void print_jvm_dup_x1();

/**
 * @brief Duplica o operando no topo da pilha e insere dois ou tres valores a baixo
 * 
 */
void print_jvm_dup_x2();

/**
 * @brief Duplica o primeiro ou os dois primeiros operandos da pilha
 * 
 */
void print_jvm_dup2();

/**
 * @brief Duplica o primeiro ou os dois primeiros operandos da pilha e insere dois ou tres valores a baixo
 * 
 */
void print_jvm_dup2_x1();

/**
 * @brief Duplica o primeiro ou os dois primeiros operandos da pilha e insere dois, tres ate quatro valores a baixo
 * 
 */
void print_jvm_dup2_x2();

/**
 * @brief Troca os dois primeiros operandos da pilha
 * 
 */
void print_jvm_swap();

/**
 * @brief soma dois inteiros
 * 
 */
void print_jvm_iadd();

/**
 * @brief soma dois longs
 * 
 */
void print_jvm_ladd();

/**
 * @brief soma dois floats
 * 
 */
void print_jvm_fadd();

/**
 * @brief soma dois doubles
 * 
 */
void print_jvm_dadd();

/**
 * @brief subtrai dois inteiros
 * 
 */
void print_jvm_isub();

/**
 * @brief subtrai dois longs
 * 
 */
void print_jvm_lsub();

/**
 * @brief subtrai dois floats
 * 
 */
void print_jvm_fsub();

/**
 * @brief subtrai dois doubles
 * 
 */
void print_jvm_dsub();

/**
 * @brief multiplica dois inteiros
 * 
 */
void print_jvm_imul();

/**
 * @brief multiplica dois longs
 * 
 */
void print_jvm_lmul();

/**
 * @brief multiplica dois floats
 * 
 */
void print_jvm_fmul();

/**
 * @brief multiplica dois doubles
 * 
 */
void print_jvm_dmul();

/**
 * @brief divide dois inteiros
 * 
 */
void print_jvm_idiv();

/**
 * @brief divide dois longs
 * 
 */
void print_jvm_ldiv();

/**
 * @brief divide dois floats
 * 
 */
void print_jvm_fdiv();

/**
 * @brief divide dois doubles
 * 
 */
void print_jvm_ddiv();

/**
 * @brief obtem o resto de dois inteiros
 * 
 */
void print_jvm_irem();

/**
 * @brief obtem o resto de dois longs
 * 
 */
void print_jvm_lrem();

/**
 * @brief obtem o resto de dois floats
 * 
 */
void print_jvm_frem();

/**
 * @brief obtem o resto de dois doubles
 * 
 */
void print_jvm_drem();

/**
 * @brief nega um inteiro
 * 
 */
void print_jvm_ineg();

/**
 * @brief nega um long
 * 
 */
void print_jvm_lneg();

/**
 * @brief nega um float
 * 
 */
void print_jvm_fneg();

/**
 * @brief nega um double
 * 
 */
void print_jvm_dneg();

/**
 * @brief shift aritmetico pra esquerda um inteiro
 * 
 */
void print_jvm_ishl();

/**
 * @brief shift aritmetico pra esquerda um long
 * 
 */
void print_jvm_lshl();

/**
 * @brief shift aritmetico pra direita um inteiro
 * 
 */
void print_jvm_ishr();

/**
 * @brief shift aritmetico pra direita um long
 * 
 */
void print_jvm_lshr();

/**
 * @brief shift logico pra direita um inteiro
 * 
 */
void print_jvm_iushr();

/**
 * @brief shift logico pra direita um long
 * 
 */
void print_jvm_lushr();

/**
 * @brief faz um AND entre dois inteiros
 * 
 */
void print_jvm_iand();

/**
 * @brief faz um AND entre dois longs
 * 
 */
void print_jvm_land();

/**
 * @brief faz um OR entre dois inteiros
 * 
 */
void print_jvm_ior();

/**
 * @brief faz um OR entre dois longs
 * 
 */
void print_jvm_lor();

/**
 * @brief faz um XOR entre dois inteiros
 * 
 */
void print_jvm_ixor();

/**
 * @brief faz um XOR entre dois longs
 * 
 */
void print_jvm_lxor();

/**
 * @brief incrementa a variavel local por uma constante
 * 
 */
void print_jvm_iinc();

/**
 * @brief conversao de int para long
 * 
 */

 
void print_jvm_i2l();

/**
 * @brief conversao de int para float
 * 
 */
void print_jvm_i2f();

/**
 * @brief conversao de int para double
 * 
 */
void print_jvm_i2d();

/**
 * @brief conversao de long para int
 * 
 */
void print_jvm_l2i();

/**
 * @brief conversao de long para float
 * 
 */
void print_jvm_l2f();

/**
 * @brief conversao de long para double
 * 
 */
void print_jvm_l2d();

/**
 * @brief conversao de float para int
 * 
 */
void print_jvm_f2i();

/**
 * @brief conversao de float para long
 * 
 */
void print_jvm_f2l();

/**
 * @brief conversao de float para double
 * 
 */
void print_jvm_f2d();

/**
 * @brief conversao de double para int
 * 
 */
void print_jvm_d2i();

/**
 * @brief conversao de double para long
 * 
 */
void print_jvm_d2l();

/**
 * @brief conversao de double para float
 * 
 */
void print_jvm_d2f();

/**
 * @brief conversao de int para byte
 * 
 */
void print_jvm_i2b();

/**
 * @brief conversao de int para char
 * 
 */
void print_jvm_i2c();

/**
 * @brief conversao de int para short
 * 
 */
void print_jvm_i2s();

/**
 * @brief compara dois longs
 * 
 */
void print_jvm_lcmp();

/**
 * @brief ambas comparam dois floats
 * 
 */
void print_jvm_fcmpl();
void print_jvm_fcmpg();

/**
 * @brief ambas comparam dois doubles
 * 
 */
void print_jvm_dcmpl();
void print_jvm_dcmpg();

/**
 * @brief todas "ifxx" fazem um branch de ints com comparacoes
 * 
 */
void print_jvm_ifeq();
void print_jvm_ifne();
void print_jvm_iflt();
void print_jvm_ifge();
void print_jvm_ifgt();
void print_jvm_ifle();

/**
 * @brief Todas fazem comparacoes entre dois inteiros
 * 
 */
void print_jvm_if_icmpeq();
void print_jvm_if_icmpne();
void print_jvm_if_icmplt();
void print_jvm_if_icmpge();
void print_jvm_if_icmpgt();
void print_jvm_if_icmple();

/**
 * @brief todas fazem um branch entre as referencias
 * 
 */
void print_jvm_if_acmpeq();
void print_jvm_if_acmpne();

/**
 * @brief pula pra um branch especifico sempre que chamada
 * 
 */
void print_jvm_goto();

/**
 * @brief pula uma subrotina
 * 
 */
void print_jvm_jsr();

/**
 * @brief retorna de uma subtorina
 * 
 */
void print_jvm_ret();

/**
 * @brief acessa a tabela pelo index e faz um pulo condicional 
 * 
 */
void print_jvm_tableswitch();

/**
 * @brief acessa a tabela por pareamento de chaves e faz um pulo condicional
 * 
 */
void print_jvm_lookupswitch();

/**
 * @brief retorna um inteiro de um metodo
 * @return integer
 */
void print_jvm_ireturn();

/**
 * @brief retorna um long de um metodo
 * @return long
 */
void print_jvm_lreturn();

/**
 * @brief retorna um float de um metodo
 * @return float
 */
void print_jvm_freturn();

/**
 * @brief retorna um double de um metodo
 * @return double
 */
void print_jvm_dreturn();

/**
 * @brief retorna uma referencia de um metodo
 *
 */
void print_jvm_areturn();

/**
 * @brief retorna void de um metodo
 * @return void
 */
void print_jvm_return();

/**
 * @brief pega um field estatico de um class
 *
 */
void print_jvm_getstatic();

/**
 * @brief seta um field estatico em um class
 *
 */
void print_jvm_putstatic();

/**
 * @brief pega um field de um objeto
 *
 */
void print_jvm_getfield();

/**
 * @brief coloca um field estatico em um objeto
 *
 */
void print_jvm_putfield();

/**
 * @brief invoca um metodo da instancia, baseado na classe
 *
 */
void print_jvm_invokevirtual();

/**
 * @brief invoca um metodo da instancia, para tratar de metodos de superclasses, privados e instanciados
 *
 */
void print_jvm_invokespecial();

/**
 * @brief invoca um metodo de instancia estatico
 *
 */
void print_jvm_invokestatic();

/**
 * @brief invoca um metodo de interface
 *
 */
void print_jvm_invokeinterface();

/**
 * @brief invoca um metodo dinamico
 *
 */
void print_jvm_invokedynamic();

/**
 * @brief cria um objeto novo
 *
 */
void print_jvm_new();

/**
 * @brief cria um vetor novo
 *
 */
void print_jvm_newarray();

/**
 * @brief cria um vetor de referencias novo
 *
 */
void print_jvm_anewarray();

/**
 * @brief recebe o tamanho do array
 *
 */
void print_jvm_arraylength();

/**
 * @brief joga uma exceção ou um erro
 *
 */
void print_jvm_athrow();

/**
 * @brief checa se o objeto eh de algum tipo
 *
 */
void print_jvm_checkcast();

/**
 * @brief verifica se o objeto eh uma instancia de alguma classe
 *
 */
void print_jvm_instanceof();
void print_jvm_monitorenter();
void print_jvm_monitorexit();

/**
 * @brief Estende a variavel local em bytes adicionais
 *
 */
void print_jvm_wide();

/**
 * @brief cria um novo vetor multidimensional
 *
 */
void print_jvm_multianewarray();

/**
 * @brief faz um branch se a referencia for nula
 *
 */
void print_jvm_ifnull();

/**
 * @brief faz um branch se a referencia for nao nula
 *
 */
void print_jvm_ifnonnull();

/**
 * @brief faz um branch sempre
 *
 */
void print_jvm_goto_w();

/**
 * @brief pula uma subrotina
 *
 */
void print_jvm_jsr_w();

/**
 * @brief cria um break em linha para debug
 *
 */
void print_jvm_breakpoint();

/**
 * @brief printa os mnemonicos para debugar
 *
 */
void print_jvm_impdep1();
void print_jvm_impdep2();
