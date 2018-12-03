#include <stdio.h>
#include "attribute_info.hpp"
#include "../ReaderFiles/read_us.hpp"

/*
* @brief Responsável pela leitura dos atributos do arquivo .class
* @bug No know bugs.
*/

/** @brief É um atributo de comprimento fixo na tabela de atributos de uma estrutura
 * field_info. Representa o valor de um campo constante.
 *  @param f
 * 	@see read_us
 *  @return 
 */

void ConstantValue_attribute  :: fill_from(FILE * f) {

	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&constantvalue_index, sizeof(constantvalue_index), f);
}

/** @brief É um atributo de tamanho fixo opcional na tabela de atributos de uma estrutura 
 * ClassFile, field_info ou method_info. Utilizado para indicar que a classe, interface, método ou 
 * campo foi substituído. Não altera a semântica de uma classe ou interface.
 *  @param f
 * 	@see read_us 
 *  @return 
 */

void Deprecated_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_length, sizeof(attribute_length), f);
}

/** @brief É um atributo opcional de comprimento fixo. O valor do index deve ser válido
 * dentro da tabela constant_pool.
 *  @param f
 * 	@see read_us 
 *  @return 
 */

void SourceFile_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&sourcefile_index, sizeof(sourcefile_index), f);
}

/** @brief É um atributo opcional de comprimento variável dentro da tabela de um atributo 
 * Code. Usado por depuradores para determinar qual parte da matriz de códigos da JVM 
 * representa um determinado número de linha no arquivo de origem original.
 *  @param f
 * 	@see read_us 
 *  @return 
 */

void LineNumberTable_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&line_number_table_length, sizeof(line_number_table_length), f);
	line_number_table = (Line_number_table *)malloc( line_number_table_length * sizeof( Line_number_table ) );
	for(int i=0;i<line_number_table_length;i++){
		line_number_table[i].fill_from(f);
	}
}

/** @brief É um atributo opcional de comprimento variável dentro da tabela de um atributo
 * Code. Usado por depuradores para determinar o valor de uma determinada variável local durante 
 * a execução de uma determinada variável local durante a execução de um método.
 *  @param f
 * 	@see read_us 
 *  @return 
 */

void LocalVariableTable_attribute  :: fill_from(FILE * f) {
	read_us(&attribute_length, sizeof(attribute_length), f);
	read_us(&local_variable_table_length, sizeof(local_variable_table_length), f);
	local_variable_table = (Local_variable_table *)malloc( local_variable_table_length * sizeof( Local_variable_table ) );
	for(int i=0;i<local_variable_table_length;i++){
		local_variable_table[i].fill_from(f);
	}
}

/** @brief 
 *  @param f
 * 	@see read_us 
 *  @return 
 */

void Line_number_table  :: fill_from(FILE * f) {
	read_us(&start_pc, sizeof(start_pc), f);
	read_us(&line_number, sizeof(line_number), f);
}

/** @brief 
 *  @param f
 * 	@see read_us 
 *  @return 
 */

void Local_variable_table  :: fill_from(FILE * f) {
	read_us(&start_pc, sizeof(start_pc), f);
	read_us(&length, sizeof(length), f);
	read_us(&name_index, sizeof(name_index), f);
	read_us(&descriptor_index, sizeof(descriptor_index), f);
	read_us(&index, sizeof(index), f);
}

/** @brief 
 *  @param f
 * 	@see read_us 
 *  @return 
 */

void Exception_Table  :: fill_from(FILE * f){
	read_us(&start_pc, sizeof(start_pc), f);
  	read_us(&end_pc, sizeof(end_pc), f);
  	read_us(&handler_pc, sizeof(handler_pc), f);
  	read_us(&catch_type, sizeof(catch_type), f);
}

/** @brief É um atributo de comprimento variável na tabela de atributos de uma estrutura
 * method_info. Contém as instruções e informações auxiliares da JVM para: um único método;
 * método de inicialização da instância; ou método de inicialização de classe ou interface.
 *  @param f
 * 	@see read_us 
 *  @return 
 */

void Code_attribute :: fill_from(FILE*f){
  	read_us(&attribute_length, sizeof(attribute_length), f);
  	read_us(&max_stack, sizeof(max_stack), f);
  	read_us(&max_locals, sizeof(max_locals), f);
  	read_us(&code_length, sizeof(code_length), f);
  	code = (u1*)malloc(sizeof(u1) * code_length);
  	read_usstring(code, code_length, f);
	read_us(&exception_table_length, sizeof(exception_table_length), f);
	exception_table = (Exception_Table *)malloc( exception_table_length * sizeof( Exception_Table ) );
	for(int i=0;i<exception_table_length;i++){
		exception_table[i].fill_from(f);
	}
  	read_us(&attributes_count, sizeof(attributes_count), f);
}

/** @brief 
 *  @param f
 * 	@see read_us 
 *  @return 
 */


void Exceptions_attribute :: fill_from(FILE * f){
  	read_us(&attribute_length, sizeof(attribute_length), f);
  	read_us(&number_of_exceptions, sizeof(number_of_exceptions), f);
	exception_index_table = (u2 *)malloc( number_of_exceptions * sizeof( u2 ) );
	for(int i=0;i<number_of_exceptions;i++){
		read_us(&exception_index_table[i], sizeof(exception_index_table[i]), f);
	}
}

/** @brief 
 *  @param f
 * 	@see read_us 
 *  @return 
 */


void Classes :: fill_from(FILE * f){
  	read_us(&inner_class_info_index, sizeof(inner_class_info_index), f);
  	read_us(&outer_class_info_index, sizeof(outer_class_info_index), f);
  	read_us(&inner_name_index, sizeof(inner_name_index), f);
  	read_us(&inner_class_access_flags, sizeof(inner_class_access_flags), f);
};

/** @brief Se a constant pool de uma classe contém uma entrada CONSTANT_Class_info que representa
 * uma classe que não é membro de um pacote, a estrutura ClassFile deverá ter um atributo
 * InnerClasses em sua tabela. Envia o arquivo f para read_us, onde é feito a leitura
 * do número de bytes. 
 *  @param f
 * 	@see read_us 
 *  @return 
 */

void InnerClasses_attribute :: fill_from(FILE * f){

  	read_us(&attribute_length, sizeof(attribute_length), f);
  	read_us(&number_of_classes, sizeof(number_of_classes), f);
	classes = (Classes *)malloc( number_of_classes * sizeof( Classes ) );
	for(int i=0;i<number_of_classes;i++){
		classes[i].fill_from(f);
	}
}





