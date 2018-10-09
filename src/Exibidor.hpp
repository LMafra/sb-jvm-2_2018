#pragma once
#include "UsingUs.hpp"
#include "ClassFileStructures/ClassFile.hpp"
#include "ClassFileStructures/cp_info.hpp"
#include <iostream>
#include <cstring>
#include <cstdio>


class Exibidor{
	ClassFile viewobj;
	/// \brief display para informacoes gerais da classse e opcoes de navegacao.
	///
	/// apresenta informacoes como magic number, versao, contadores e flags de acesso.
	/// mostra opcoes de navegacao para constant pool, metodos, atributos, fields e interfaces.
	void displayClassFile(ClassFile & theclass);
	/// \brief display para class info.
	///
	/// apresenta o cp info com o nome da classe.
	void displayCONSTANT_Class_info(CONSTANT_Class_info & theclassinfo);
	/// \brief display para fieldref info.
	///
	/// apresenta o cp info com o nome da classe que contem o field, e nome e tipo do field.
	void displayCONSTANT_Fieldref_info(CONSTANT_Fieldref_info & thefieldinfo);
	/// \brief display para name and type info.
	///
	/// apresenta o cp info com o nome do metodo/field e o tipo do metodo/field.
	void displayCONSTANT_NameAndType_info(CONSTANT_NameAndType_info & thenameandtypeinfo);
	/// \brief display para constantes utf8.
	///
	/// apresenta o cp info com o tamanho da string e a string em si.
	void displayCONSTANT_Utf8_info(CONSTANT_Utf8_info & theunistringinfo);
	/// \brief display para methodref info.
	///
	/// apresenta o cp info com o nome da classe que contem o metodo, e nome e tipo do metodo.
	void displayCONSTANT_Methodref_info(CONSTANT_Methodref_info & themethodinfo);
	/// \brief display para methodref info.
	///
	/// apresenta o cp info com o nome da classe que contem o metodo, e nome e tipo do metodo.
	void displayCONSTANT_InterfaceMethodref_info(CONSTANT_InterfaceMethodref_info & themethodinfo);
	/// \brief display para string info.
	///
	/// apresenta o cp info com o indice da string.
	void displayCONSTANT_String_info(CONSTANT_String_info & thestringinfo);
	/// \brief display para int info.
	///
	/// apresenta o cp info com o numero constante.
	void displayCONSTANT_Integer_info(CONSTANT_Integer_info & theintinfo);
	/// \brief display para float info.
	///
	/// apresenta o cp info com o numero constante.
	void displayCONSTANT_Float_info(CONSTANT_Float_info & thefloatinfo);
	/// \brief display para long info.
	///
	/// apresenta o cp info com o numero constante.
	void displayCONSTANT_Long_info(CONSTANT_Long_info & thelonginfo);
	/// \brief display para double info.
	///
	/// apresenta o cp info com o numero constante.
	void displayCONSTANT_Double_info(CONSTANT_Double_info & thedoubleinfo);
	/// \brief display para entradas na tabela de constantes.
	///
	/// apresenta lista de entradas da CP.
	/// mostra opcoes de navegacao para constant pool.
	void displayconstant_pool(ClassFile & theclass);
	/// \brief entrada do exibidor.
	///
	/// mostra opcoes na tela e controla fluxo de input/output.
	/// opcoes lidas como entrada numerica.
	void control_class();
	/// \brief arvore de constant pool.
	///
	/// lista todas as constantes e seleciona uma para mostrar.
	/// opcoes lidas como entrada numerica.
	void control_cp();
	void controlCONSTANT_Class_info(CONSTANT_Class_info & theclassinfo);
	void controlCONSTANT_Fieldref_info(CONSTANT_Fieldref_info * thefieldinfo);
	void controlCONSTANT_NameAndType_info(CONSTANT_NameAndType_info * thenameandtypeinfo);
	void controlCONSTANT_Utf8_info(CONSTANT_Utf8_info & theunistringinfo);
	void controlCONSTANT_Methodref_info(CONSTANT_Methodref_info * themethodinfo);
	void controlCONSTANT_InterfaceMethodref_info(CONSTANT_InterfaceMethodref_info * themethodinfo);
	void controlCONSTANT_String_info(CONSTANT_String_info * thestringinfo);
	void controlCONSTANT_Integer_info(CONSTANT_Integer_info * theintinfo);
	void controlCONSTANT_Float_info(CONSTANT_Float_info * thefloatinfo);
	void controlCONSTANT_Long_info(CONSTANT_Long_info * thelonginfo);
	void controlCONSTANT_Double_info(CONSTANT_Double_info * thedoubleinfo);
	void clearlinesprint();
public:
	void feed(ClassFile toshow);
	void show();
};

#include "Exibidor.cpp"
