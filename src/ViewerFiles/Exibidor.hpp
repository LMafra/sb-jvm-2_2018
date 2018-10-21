#pragma once
#include "../UsingUs.hpp"
#include "../ClassFileStructures/ClassFile.hpp"
#include "../ClassFileStructures/cp_info.hpp"
#include "../ClassFileStructures/attribute_info.hpp"
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
	void displayClassFileFlags(ClassFile & theclass);
	void displayClassInfoString(CONSTANT_Class_info & theinfo);
	void displayUtf8InfoString(CONSTANT_Utf8_info & theinfo);
	void displayClassInfoStringRaw(CONSTANT_Class_info & theinfo);
	void displayUtf8InfoStringRaw(CONSTANT_Utf8_info & theinfo);
	void displayNameTypeInfoString(CONSTANT_NameAndType_info & theinfo);
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


	void displayConstantValueAtt(ConstantValue_attribute & theatt, int indent);
	void displayCodeAtt(Code_attribute & theatt, int indent);
	void displayDeprecatedAtt(Deprecated_attribute & theatt, int indent);
	void displayExceptionsAtt(Exceptions_attribute & theatt, int indent);
	void displayInnerClassesFlags(u2 accflags);
	void displayInnerClassesAtt(InnerClasses_attribute & theatt, int indent);
	void displaySourceFileAtt(SourceFile_attribute & theatt, int indent);
	void displayLineNumberTableAtt(LineNumberTable_attribute & theatt, int indent);
	void displayLocalVariableTableAtt(LocalVariableTable_attribute & theatt, int indent);

	void displayfields(ClassFile & theclass);
	void displayMethodsFlags(u2 accflags);
	void displaymethods(ClassFile & theclass);
	att_name_result attributenamecompare(CONSTANT_Utf8_info & name);
	void printindent(int indent);
	void displayAttributes(attribute_info * attlist, int length, int indent);
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
	void control_fields();
	void control_attributes();
	void control_methods();
	void printparammethodname(u2 index);
	void printparamfieldname(u2 index);
	void printparamcat2value(u2 index);
public:
	/// \brief fornece estrutura de ClassFile a ser exibida.
	///
	/// a estrutura e copiada e armazenada pelo exibidor.
	/// futuros feeds substituem a estrutura.
	void feed(ClassFile toshow);
	/// \brief inicia a exibicao da classe armazenada.
	///
	/// o fluxo de exibicao inclui input e output.
	/// a output inclui as "telas" que mostram informacao e opcoes.
	/// a input inclui selecao de opcoes de navegacao pelo usuario
	void show();
};

#include "Exibidor.cpp"
