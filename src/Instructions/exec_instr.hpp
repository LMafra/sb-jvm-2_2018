#pragma once
#include "../UsingUs.h"


/**
 * @brief Nao faz nada
 * 
 */
void exec_jvm_nop();

/**
 * @brief Empilha um null na pilha
 * 
 */
void exec_jvm_aconst_null();

/**
 * @brief Todos iconst empilham um int que eh uma constante na pilha
 * 
 */
void exec_jvm_iconst_m1();
void exec_jvm_iconst_0();
void exec_jvm_iconst_1();
void exec_jvm_iconst_2();
void exec_jvm_iconst_3();
void exec_jvm_iconst_4();
void exec_jvm_iconst_5();
/**
 * @brief Todos lconst empilham um long int que é constante na pilha
 * 
 */
void exec_jvm_lconst_0();
void exec_jvm_lconst_1();

/**
 * @brief Todos fconst empilha um float na pilha
 * 
 */
void exec_jvm_fconst_0();
void exec_jvm_fconst_1();
void exec_jvm_fconst_2();

/**
 * @brief Todos dconst empilham um double na pilha
 * 
 */
void exec_jvm_dconst_0();
void exec_jvm_dconst_1();

/**
 * @brief Empilha um byte na pilha
 * 
 */
void exec_jvm_bipush();

/**
 * @brief Empilha um short na pilha
 * 
 */
void exec_jvm_sipush();

/**
 * @brief Empilha um item da constant pool na pilha
 * 
 */
void exec_jvm_ldc();

/**
 * @brief Empilha um item da constant pool de wind index na pilha
 * 
 */
void exec_jvm_ldc_w();

/**
 * @brief Empilha um long ou um double da constant pool na pilha
 * 
 */
void exec_jvm_ldc2_w();

/**
 * @brief Carrega um int de uma variavel local
 * 
 */
void exec_jvm_iload();

/**
 * @brief Carrega um long de uma variavel local
 * 
 */
void exec_jvm_lload();

/**
 * @brief Carrega um float de uma variavel local
 * 
 */
void exec_jvm_fload();

/**
 * @brief Carrega um double de uma variavel local
 * 
 */
void exec_jvm_dload();

/**
 * @brief Carrega uma referencia de uma variavel local
 * 
 */
void exec_jvm_aload();

/**
 * @brief Todos iloads<n> carregam um int de uma variavel local
 * 
 */
void exec_jvm_iload_0();
void exec_jvm_iload_1();
void exec_jvm_iload_2();
void exec_jvm_iload_3();

/**
 * @brief Todos floads<n> carregam um long de uma variavel local
 * 
 */
void exec_jvm_lload_0();
void exec_jvm_lload_1();
void exec_jvm_lload_2();
void exec_jvm_lload_3();

/**
 * @brief Todos floads<n> carregam um float de uma variavel local
 * 
 */
void exec_jvm_fload_0();
void exec_jvm_fload_1();
void exec_jvm_fload_2();
void exec_jvm_fload_3();

/**
 * @brief Todos dloads<n> carregam um double de uma variavel local
 * 
 */
void exec_jvm_dload_0();
void exec_jvm_dload_1();
void exec_jvm_dload_2();
void exec_jvm_dload_3();

/**
 * @brief Todos aloads<n> carregam uma referencia de uma variavel local
 * 
 */
void exec_jvm_aload_0();
void exec_jvm_aload_1();
void exec_jvm_aload_2();
void exec_jvm_aload_3();

/**
 * @brief Carrega um int de um vetor
 * 
 */
void exec_jvm_iaload();

/**
 * @brief Carrega um float de um vetor
 * 
 */
void exec_jvm_faload();

/**
 * @brief Carrega um double de um vetor
 * 
 */
void exec_jvm_daload();

/**
 * @brief Carrega uma referencia de um vetor
 * 
 */
void exec_jvm_aaload();

/**
 * @brief Carrega um byte ou um boolean de um vetor
 * 
 */
void exec_jvm_baload();

/**
 * @brief Carrega um char de um vetor
 * 
 */
void exec_jvm_caload();

/**
 * @brief Carrega um short de um vetor
 * 
 */
void exec_jvm_saload();

/**
 * @brief Armazena um int em uma variavel local
 * 
 */
void exec_jvm_istore();

/**
 * @brief Armazena um long em uma variavel local
 * 
 */
void exec_jvm_lstore();

/**
 * @brief Armazena um float em uma variavel local
 * 
 */
void exec_jvm_fstore();

/**
 * @brief Armazena um double em uma variavel local
 * 
 */
void exec_jvm_dstore();

/**
 * @brief Armazena uma referencia em uma variavel local
 * 
 */
void exec_jvm_astore();

/**
 * @brief Todos os istore_<n> armazenam um int numa variavel local
 * 
 */
void exec_jvm_istore_0();
void exec_jvm_istore_1();
void exec_jvm_istore_2();
void exec_jvm_istore_3();

/**
 * @brief Todos os lstore_<n> armazenam um long numa variavel local
 * 
 */
void exec_jvm_lstore_0();
void exec_jvm_lstore_1();
void exec_jvm_lstore_2();
void exec_jvm_lstore_3();

/**
 * @brief Todos os fstore_<n> armazenam um float numa variavel local
 * 
 */
void exec_jvm_fstore_0();
void exec_jvm_fstore_1();
void exec_jvm_fstore_2();
void exec_jvm_fstore_3();

/**
 * @brief Todos os dstore_<n> armazenam um double numa variavel local
 * 
 */
void exec_jvm_dstore_0();
void exec_jvm_dstore_1();
void exec_jvm_dstore_2();
void exec_jvm_dstore_3();

/**
 * @brief Todos os astore_<n> armazenam uma referencia numa variavel local
 * 
 */
void exec_jvm_astore_0();
void exec_jvm_astore_1();
void exec_jvm_astore_2();
void exec_jvm_astore_3();

/**
 * @brief Armazena num vetor de inteiros
 * 
 */
void exec_jvm_iastore();

/**
 * @brief Armazena num vetor de long
 * 
 */
void exec_jvm_lastore();

/**
 * @brief Armazena num vetor de float
 * 
 */
void exec_jvm_fastore();

/**
 * @brief Armazena num vetor de double
 * 
 */
void exec_jvm_dastore();

/**
 * @brief Armazena num vetor de referencias
 * 
 */
void exec_jvm_aastore();

/**
 * @brief Armazena num vetor de byte ou booleans
 * 
 */
void exec_jvm_bastore();

/**
 * @brief Armazena num vetor de char
 * 
 */
void exec_jvm_castore();

/**
 * @brief Armazena num vetor de short
 * 
 */
void exec_jvm_sastore();

/**
 * @brief Desempilha um valor da pilha de operandos
 * 
 */
void exec_jvm_pop();

/**
 * @brief Desempilha um ou dois valores da pilha de operandos
 * 
 */
void exec_jvm_pop2();

/**
 * @brief Duplica o operando no topo da pilha
 * 
 */
void exec_jvm_dup();

/**
 * @brief Duplica o operando no topo da pilha e insere dois valores a baixo
 * 
 */
void exec_jvm_dup_x1();

/**
 * @brief Duplica o operando no topo da pilha e insere dois ou tres valores a baixo
 * 
 */
void exec_jvm_dup_x2();

/**
 * @brief Duplica o primeiro ou os dois primeiros operandos da pilha
 * 
 */
void exec_jvm_dup2();

/**
 * @brief Duplica o primeiro ou os dois primeiros operandos da pilha e insere dois ou tres valores a baixo
 * 
 */
void exec_jvm_dup2_x1();

/**
 * @brief Duplica o primeiro ou os dois primeiros operandos da pilha e insere dois, tres ate quatro valores a baixo
 * 
 */
void exec_jvm_dup2_x2();

/**
 * @brief Troca os dois primeiros operandos da pilha
 * 
 */
void exec_jvm_swap();

/**
 * @brief soma dois inteiros
 * 
 */
void exec_jvm_iadd();

/**
 * @brief soma dois longs
 * 
 */
void exec_jvm_ladd();

/**
 * @brief soma dois floats
 * 
 */
void exec_jvm_fadd();

/**
 * @brief soma dois doubles
 * 
 */
void exec_jvm_dadd();

/**
 * @brief subtrai dois inteiros
 * 
 */
void exec_jvm_isub();

/**
 * @brief subtrai dois longs
 * 
 */
void exec_jvm_lsub();

/**
 * @brief subtrai dois floats
 * 
 */
void exec_jvm_fsub();

/**
 * @brief subtrai dois doubles
 * 
 */
void exec_jvm_dsub();

/**
 * @brief multiplica dois inteiros
 * 
 */
void exec_jvm_imul();

/**
 * @brief multiplica dois longs
 * 
 */
void exec_jvm_lmul();

/**
 * @brief multiplica dois floats
 * 
 */
void exec_jvm_fmul();

/**
 * @brief multiplica dois doubles
 * 
 */
void exec_jvm_dmul();

/**
 * @brief divide dois inteiros
 * 
 */
void exec_jvm_idiv();

/**
 * @brief divide dois longs
 * 
 */
void exec_jvm_ldiv();

/**
 * @brief divide dois floats
 * 
 */
void exec_jvm_fdiv();

/**
 * @brief divide dois doubles
 * 
 */
void exec_jvm_ddiv();

/**
 * @brief obtem o resto de dois inteiros
 * 
 */
void exec_jvm_irem();

/**
 * @brief obtem o resto de dois longs
 * 
 */
void exec_jvm_lrem();

/**
 * @brief obtem o resto de dois floats
 * 
 */
void exec_jvm_frem();

/**
 * @brief obtem o resto de dois doubles
 * 
 */
void exec_jvm_drem();

/**
 * @brief nega um inteiro
 * 
 */
void exec_jvm_ineg();

/**
 * @brief nega um long
 * 
 */
void exec_jvm_lneg();

/**
 * @brief nega um float
 * 
 */
void exec_jvm_fneg();

/**
 * @brief nega um double
 * 
 */
void exec_jvm_dneg();

/**
 * @brief shift aritmetico pra esquerda um inteiro
 * 
 */
void exec_jvm_ishl();

/**
 * @brief shift aritmetico pra esquerda um long
 * 
 */
void exec_jvm_lshl();

/**
 * @brief shift aritmetico pra direita um inteiro
 * 
 */
void exec_jvm_ishr();

/**
 * @brief shift aritmetico pra direita um long
 * 
 */
void exec_jvm_lshr();

/**
 * @brief shift logico pra direita um inteiro
 * 
 */
void exec_jvm_iushr();

/**
 * @brief shift logico pra direita um long
 * 
 */
void exec_jvm_lushr();

/**
 * @brief faz um AND entre dois inteiros
 * 
 */
void exec_jvm_iand();

/**
 * @brief faz um AND entre dois longs
 * 
 */
void exec_jvm_land();

/**
 * @brief faz um OR entre dois inteiros
 * 
 */
void exec_jvm_ior();

/**
 * @brief faz um OR entre dois longs
 * 
 */
void exec_jvm_lor();

/**
 * @brief faz um XOR entre dois inteiros
 * 
 */
void exec_jvm_ixor();

/**
 * @brief faz um XOR entre dois longs
 * 
 */
void exec_jvm_lxor();

/**
 * @brief incrementa a variavel local por uma constante
 * 
 */
void exec_jvm_iinc();

/**
 * @brief conversao de int para long
 * 
 */

 
void exec_jvm_i2l();

/**
 * @brief conversao de int para float
 * 
 */
void exec_jvm_i2f();

/**
 * @brief conversao de int para double
 * 
 */
void exec_jvm_i2d();

/**
 * @brief conversao de long para int
 * 
 */
void exec_jvm_l2i();

/**
 * @brief conversao de long para float
 * 
 */
void exec_jvm_l2f();

/**
 * @brief conversao de long para double
 * 
 */
void exec_jvm_l2d();

/**
 * @brief conversao de float para int
 * 
 */
void exec_jvm_f2i();

/**
 * @brief conversao de float para long
 * 
 */
void exec_jvm_f2l();

/**
 * @brief conversao de float para double
 * 
 */
void exec_jvm_f2d();

/**
 * @brief conversao de double para int
 * 
 */
void exec_jvm_d2i();

/**
 * @brief conversao de double para long
 * 
 */
void exec_jvm_d2l();

/**
 * @brief conversao de double para float
 * 
 */
void exec_jvm_d2f();

/**
 * @brief conversao de int para byte
 * 
 */
void exec_jvm_i2b();

/**
 * @brief conversao de int para char
 * 
 */
void exec_jvm_i2c();

/**
 * @brief conversao de int para short
 * 
 */
void exec_jvm_i2s();

/**
 * @brief compara dois longs
 * 
 */
void exec_jvm_lcmp();

/**
 * @brief ambas comparam dois floats
 * 
 */
void exec_jvm_fcmpl();
void exec_jvm_fcmpg();

/**
 * @brief ambas comparam dois doubles
 * 
 */
void exec_jvm_dcmpl();
void exec_jvm_dcmpg();

/**
 * @brief todas "ifxx" fazem um branch de ints com comparacoes
 * 
 */
void exec_jvm_ifeq();
void exec_jvm_ifne();
void exec_jvm_iflt();
void exec_jvm_ifge();
void exec_jvm_ifgt();
void exec_jvm_ifle();

/**
 * @brief Todas fazem comparacoes entre dois inteiros
 * 
 */
void exec_jvm_if_icmpeq();
void exec_jvm_if_icmpne();
void exec_jvm_if_icmplt();
void exec_jvm_if_icmpge();
void exec_jvm_if_icmpgt();
void exec_jvm_if_icmple();

/**
 * @brief todas fazem um branch entre as referencias
 * 
 */
void exec_jvm_if_acmpeq();
void exec_jvm_if_acmpne();

/**
 * @brief pula pra um branch especifico sempre que chamada
 * 
 */
void exec_jvm_goto();

/**
 * @brief pula uma subrotina
 * 
 */
void exec_jvm_jsr();

/**
 * @brief retorna de uma subtorina
 * 
 */
void exec_jvm_ret();

/**
 * @brief acessa a tabela pelo index e faz um pulo condicional 
 * 
 */
void exec_jvm_tableswitch();

/**
 * @brief acessa a tabela por pareamento de chaves e faz um pulo condicional
 * 
 */
void exec_jvm_lookupswitch();

/**
 * @brief retorna um inteiro de um metodo
 * @return integer
 */
void exec_jvm_ireturn();

/**
 * @brief retorna um long de um metodo
 * @return long
 */
void exec_jvm_lreturn();

/**
 * @brief retorna um float de um metodo
 * @return float
 */
void exec_jvm_freturn();

/**
 * @brief retorna um double de um metodo
 * @return double
 */
void exec_jvm_dreturn();

/**
 * @brief retorna uma referencia de um metodo
 *
 */
void exec_jvm_areturn();

/**
 * @brief retorna void de um metodo
 * @return void
 */
void exec_jvm_return();

/**
 * @brief pega um field estatico de um class
 *
 */
void exec_jvm_getstatic();

/**
 * @brief seta um field estatico em um class
 *
 */
void exec_jvm_putstatic();

/**
 * @brief pega um field de um objeto
 *
 */
void exec_jvm_getfield();

/**
 * @brief coloca um field estatico em um objeto
 *
 */
void exec_jvm_putfield();

/**
 * @brief invoca um metodo da instancia, baseado na classe
 *
 */
void exec_jvm_invokevirtual();

/**
 * @brief invoca um metodo da instancia, para tratar de metodos de superclasses, privados e instanciados
 *
 */
void exec_jvm_invokespecial();

/**
 * @brief invoca um metodo de instancia estatico
 *
 */
void exec_jvm_invokestatic();

/**
 * @brief invoca um metodo de interface
 *
 */
void exec_jvm_invokeinterface();

/**
 * @brief invoca um metodo dinamico
 *
 */
void exec_jvm_invokedynamic();

/**
 * @brief cria um objeto novo
 *
 */
void exec_jvm_new();

/**
 * @brief cria um vetor novo
 *
 */
void exec_jvm_newarray();

/**
 * @brief cria um vetor de referencias novo
 *
 */
void exec_jvm_anewarray();

/**
 * @brief recebe o tamanho do array
 *
 */
void exec_jvm_arraylength();

/**
 * @brief joga uma exceção ou um erro
 *
 */
void exec_jvm_athrow();

/**
 * @brief checa se o objeto eh de algum tipo
 *
 */
void exec_jvm_checkcast();

/**
 * @brief verifica se o objeto eh uma instancia de alguma classe
 *
 */
void exec_jvm_instanceof();
void exec_jvm_monitorenter();
void exec_jvm_monitorexit();

/**
 * @brief Estende a variavel local em bytes adicionais
 *
 */
void exec_jvm_wide();

/**
 * @brief cria um novo vetor multidimensional
 *
 */
void exec_jvm_multianewarray();

/**
 * @brief faz um branch se a referencia for nula
 *
 */
void exec_jvm_ifnull();

/**
 * @brief faz um branch se a referencia for nao nula
 *
 */
void exec_jvm_ifnonnull();

/**
 * @brief faz um branch sempre
 *
 */
void exec_jvm_goto_w();

/**
 * @brief pula uma subrotina
 *
 */
void exec_jvm_jsr_w();

/**
 * @brief cria um break em linha para debug
 *
 */
void exec_jvm_breakpoint();

/**
 * @brief execa os mnemonicos para debugar
 *
 */
void exec_jvm_impdep1();
void exec_jvm_impdep2();

// Rofl - O que eu fiz aqui, peguei o outro arquivo que comentei, e joguei aqui, soh
//        que a diferença foi que mudei todos os print_ pra exec_. Deixei aqui em baixo o que ja tinha 
//        caso ocorra algo inesperado.

// void exec_jvm_nop();
// void exec_jvm_aconst_null();
// void exec_jvm_iconst_m1();
// void exec_jvm_iconst_0();
// void exec_jvm_iconst_1();
// void exec_jvm_iconst_2();
// void exec_jvm_iconst_3();
// void exec_jvm_iconst_4();
// void exec_jvm_iconst_5();
// void exec_jvm_lconst_0();
// void exec_jvm_lconst_1();
// void exec_jvm_fconst_0();
// void exec_jvm_fconst_1();
// void exec_jvm_fconst_2();
// void exec_jvm_dconst_0();
// void exec_jvm_dconst_1();
// void exec_jvm_bipush();
// void exec_jvm_sipush();
// void exec_jvm_ldc();
// void exec_jvm_ldc_w();
// void exec_jvm_ldc2_w();
// void exec_jvm_iload();
// void exec_jvm_lload();
// void exec_jvm_fload();
// void exec_jvm_dload();
// void exec_jvm_aload();
// void exec_jvm_iload_0();
// void exec_jvm_iload_1();
// void exec_jvm_iload_2();
// void exec_jvm_iload_3();
// void exec_jvm_lload_0();
// void exec_jvm_lload_1();
// void exec_jvm_lload_2();
// void exec_jvm_lload_3();
// void exec_jvm_fload_0();
// void exec_jvm_fload_1();
// void exec_jvm_fload_2();
// void exec_jvm_fload_3();
// void exec_jvm_dload_0();
// void exec_jvm_dload_1();
// void exec_jvm_dload_2();
// void exec_jvm_dload_3();
// void exec_jvm_aload_0();
// void exec_jvm_aload_1();
// void exec_jvm_aload_2();
// void exec_jvm_aload_3();
// void exec_jvm_iaload();
// void exec_jvm_faload();
// void exec_jvm_daload();
// void exec_jvm_aaload();
// void exec_jvm_baload();
// void exec_jvm_caload();
// void exec_jvm_saload();
// void exec_jvm_istore();
// void exec_jvm_lstore();
// void exec_jvm_fstore();
// void exec_jvm_dstore();
// void exec_jvm_astore();
// void exec_jvm_istore_0();
// void exec_jvm_istore_1();
// void exec_jvm_istore_2();
// void exec_jvm_istore_3();
// void exec_jvm_lstore_0();
// void exec_jvm_lstore_1();
// void exec_jvm_lstore_2();
// void exec_jvm_lstore_3();
// void exec_jvm_fstore_0();
// void exec_jvm_fstore_1();
// void exec_jvm_fstore_2();
// void exec_jvm_fstore_3();
// void exec_jvm_dstore_0();
// void exec_jvm_dstore_1();
// void exec_jvm_dstore_2();
// void exec_jvm_dstore_3();
// void exec_jvm_astore_0();
// void exec_jvm_astore_1();
// void exec_jvm_astore_2();
// void exec_jvm_astore_3();
// void exec_jvm_iastore();
// void exec_jvm_lastore();
// void exec_jvm_fastore();
// void exec_jvm_dastore();
// void exec_jvm_aastore();
// void exec_jvm_bastore();
// void exec_jvm_castore();
// void exec_jvm_sastore();
// void exec_jvm_pop();
// void exec_jvm_pop2();
// void exec_jvm_dup();
// void exec_jvm_dup_x1();
// void exec_jvm_dup_x2();
// void exec_jvm_dup2();
// void exec_jvm_dup2_x1();
// void exec_jvm_dup2_x2();
// void exec_jvm_swap();
// void exec_jvm_iadd();
// void exec_jvm_ladd();
// void exec_jvm_fadd();
// void exec_jvm_dadd();
// void exec_jvm_isub();
// void exec_jvm_lsub();
// void exec_jvm_fsub();
// void exec_jvm_dsub();
// void exec_jvm_imul();
// void exec_jvm_lmul();
// void exec_jvm_fmul();
// void exec_jvm_dmul();
// void exec_jvm_idiv();
// void exec_jvm_ldiv();
// void exec_jvm_fdiv();
// void exec_jvm_ddiv();
// void exec_jvm_irem();
// void exec_jvm_lrem();
// void exec_jvm_frem();
// void exec_jvm_drem();
// void exec_jvm_ineg();
// void exec_jvm_lneg();
// void exec_jvm_fneg();
// void exec_jvm_dneg();
// void exec_jvm_ishl();
// void exec_jvm_lshl();
// void exec_jvm_ishr();
// void exec_jvm_lshr();
// void exec_jvm_iushr();
// void exec_jvm_lushr();
// void exec_jvm_iand();
// void exec_jvm_land();
// void exec_jvm_ior();
// void exec_jvm_lor();
// void exec_jvm_ixor();
// void exec_jvm_lxor();
// void exec_jvm_iinc();
// void exec_jvm_i2l();
// void exec_jvm_i2f();
// void exec_jvm_i2d();
// void exec_jvm_l2i();
// void exec_jvm_l2f();
// void exec_jvm_l2d();
// void exec_jvm_f2i();
// void exec_jvm_f2l();
// void exec_jvm_f2d();
// void exec_jvm_d2i();
// void exec_jvm_d2l();
// void exec_jvm_d2f();
// void exec_jvm_i2b();
// void exec_jvm_i2c();
// void exec_jvm_i2s();
// void exec_jvm_lcmp();
// void exec_jvm_fcmpl();
// void exec_jvm_fcmpg();
// void exec_jvm_dcmpl();
// void exec_jvm_dcmpg();
// void exec_jvm_ifeq();
// void exec_jvm_ifne();
// void exec_jvm_iflt();
// void exec_jvm_ifge();
// void exec_jvm_ifgt();
// void exec_jvm_ifle();
// void exec_jvm_if_icmpeq();
// void exec_jvm_if_icmpne();
// void exec_jvm_if_icmplt();
// void exec_jvm_if_icmpge();
// void exec_jvm_if_icmpgt();
// void exec_jvm_if_icmple();
// void exec_jvm_if_acmpeq();
// void exec_jvm_if_acmpne();
// void exec_jvm_goto();
// void exec_jvm_jsr();
// void exec_jvm_ret();
// void exec_jvm_tableswitch();
// void exec_jvm_lookupswitch();
// void exec_jvm_ireturn();
// void exec_jvm_lreturn();
// void exec_jvm_freturn();
// void exec_jvm_dreturn();
// void exec_jvm_areturn();
// void exec_jvm_return();
// void exec_jvm_getstatic();
// void exec_jvm_putstatic();
// void exec_jvm_getfield();
// void exec_jvm_putfield();
// void exec_jvm_invokevirtual();
// void exec_jvm_invokespecial();
// void exec_jvm_invokestatic();
// void exec_jvm_invokeinterface();
// void exec_jvm_invokedynamic();
// void exec_jvm_new();
// void exec_jvm_newarray();
// void exec_jvm_anewarray();
// void exec_jvm_arraylength();
// void exec_jvm_athrow();
// void exec_jvm_checkcast();
// void exec_jvm_instanceof();
// void exec_jvm_monitorenter();
// void exec_jvm_monitorexit();
// void exec_jvm_wide();
// void exec_jvm_multianewarray();
// void exec_jvm_ifnull();
// void exec_jvm_ifnonnull();
// void exec_jvm_goto_w();
// void exec_jvm_jsr_w();
// void exec_jvm_breakpoint();
// void exec_jvm_impdep1();
// void exec_jvm_impdep2();
