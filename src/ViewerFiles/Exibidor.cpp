#include "Exibidor.hpp"

void Exibidor::displayClassFile(ClassFile & theclass){  // TODO encontrar this class e super class na constant pool para exibir
	/// imprime os dados gerais de class file.
	///
	std::cout << "class file:" << std::endl;
	std::cout << "  Minor version: " << theclass.minor_version << std::endl;
	std::cout << "  Major version: " << theclass.major_version << std::endl;
	std::cout << "  Constant Pool Count: " << theclass.constant_pool_count << std::endl;
	// TODO apresentar mnemonicos das flags
	std::cout << "  Access Flags: " << std::hex << std::showbase << std::uppercase << theclass.access_flags << " ";
	displayClassFileFlags(theclass);
	std::cout << std::endl << std::dec;
	std::cout << "  This Class: cp_info# " << theclass.this_class << " ";
	displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theclass.this_class]);
	std::cout << std::endl;
	std::cout << "  Super Class: cp_info# " << theclass.super_class << " ";
	displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theclass.super_class]);
	std::cout << std::endl;
	std::cout << "  Interfaces Count: " << theclass.interfaces_count << std::endl;
	std::cout << "  Fields Count: " << theclass.fields_count << std::endl;
	std::cout << "  Methods Count: " << theclass.methods_count << std::endl;
	std::cout << "  Attributes Count: " << theclass.attributes_count << std::endl;
	std::cout << std::endl << std::endl;
}

void Exibidor::displayClassFileFlags(ClassFile & theclass){
	if (theclass.access_flags & ClassFileFlags::ACC_PUBLIC){
		printf("[public]");
	}
	if (theclass.access_flags & ClassFileFlags::ACC_FINAL){
		printf("[final]");
	}
	if (theclass.access_flags & ClassFileFlags::ACC_SUPER){
		printf("[super]");
	}
	if (theclass.access_flags & ClassFileFlags::ACC_INTERFACE){
		printf("[interface]");
	}
	if (theclass.access_flags & ClassFileFlags::ACC_ABSTRACT){
		printf("[abstract]");
	}
}

void Exibidor::displayClassInfoString(CONSTANT_Class_info & theinfo){
	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theinfo.name_index]);
}

void Exibidor::displayUtf8InfoString(CONSTANT_Utf8_info & theinfo){
	std::cout << "<";
	for(int i=0;i<theinfo.length;i++)
		std::cout << (u1)theinfo.bytes[i];
	std::cout << ">";
}

void Exibidor::displayNameTypeInfoString(CONSTANT_NameAndType_info & theinfo){
	CONSTANT_Utf8_info & aux = *(CONSTANT_Utf8_info *)&viewobj.constant_pool[theinfo.name_index];
	CONSTANT_Utf8_info & aux2 = *(CONSTANT_Utf8_info *)&viewobj.constant_pool[theinfo.descriptor_index];
	std::cout << "<";
	for(int i=0;i<aux.length;i++)
		std::cout << (u1)aux.bytes[i];
	std::cout << " : ";
	for(int i=0;i<aux2.length;i++)
		std::cout << (u1)aux2.bytes[i];
	std::cout << ">";
}

void Exibidor::displayCONSTANT_Class_info(CONSTANT_Class_info & theclassinfo){
	std::cout << "\tClass Name: cp_info# " << theclassinfo.name_index << " ";
	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theclassinfo.name_index]);
	std::cout << std::endl;
	std::cout << std::endl;
}

void Exibidor::displayCONSTANT_Fieldref_info(CONSTANT_Fieldref_info & thefieldinfo){
	std::cout << "\tClass/Interface Name: cp_info# " << thefieldinfo.class_index << " ";
	displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[thefieldinfo.class_index]);
	std::cout << std::endl;
	std::cout << "\tName and Type: cp_info# " << thefieldinfo.name_and_type_index << " ";
	displayNameTypeInfoString(*(CONSTANT_NameAndType_info *)&viewobj.constant_pool[thefieldinfo.name_and_type_index]);
	std::cout << std::endl;
	std::cout << std::endl;
}

void Exibidor::displayCONSTANT_NameAndType_info(CONSTANT_NameAndType_info & thenameandtypeinfo){
	std::cout << "\tName: cp_info# " << thenameandtypeinfo.name_index << " ";
	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[thenameandtypeinfo.name_index]);
	std::cout << std::endl;
	std::cout << "\tType Descriptor: cp_info# " << thenameandtypeinfo.descriptor_index << " ";
	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[thenameandtypeinfo.descriptor_index]);
	std::cout << std::endl;
	std::cout << std::endl;
}

void Exibidor::displayCONSTANT_Utf8_info(CONSTANT_Utf8_info & theunistringinfo){
	std::cout << "\t";
	for(int i=0;i<theunistringinfo.length;i++)
		std::cout << (u1)theunistringinfo.bytes[i];
	std::cout << std::endl;
	std::cout << std::endl;
}

void Exibidor::displayCONSTANT_Methodref_info(CONSTANT_Methodref_info & themethodinfo){
	std::cout << "\tClass/Interface Name: cp_info# " << themethodinfo.class_index << " ";
	displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[themethodinfo.class_index]);
	std::cout << std::endl;
	std::cout << "\tName and Type: cp_info# " << themethodinfo.name_and_type_index << " ";
	displayNameTypeInfoString(*(CONSTANT_NameAndType_info *)&viewobj.constant_pool[themethodinfo.name_and_type_index]);
	std::cout << std::endl;
	std::cout << std::endl;
}

void Exibidor::displayCONSTANT_InterfaceMethodref_info(CONSTANT_InterfaceMethodref_info & themethodinfo){
	std::cout << "\tInterface Name: cp_info# " << themethodinfo.class_index << " ";
	displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[themethodinfo.class_index]);
	std::cout << std::endl;
	std::cout << "\tName and Type: cp_info# " << themethodinfo.name_and_type_index << " ";
	displayNameTypeInfoString(*(CONSTANT_NameAndType_info *)&viewobj.constant_pool[themethodinfo.name_and_type_index]);
	std::cout << std::endl;
	std::cout << std::endl;
}

void Exibidor::displayCONSTANT_String_info(CONSTANT_String_info & thestringinfo){
	std::cout << "\tString Text: cp_info# " << thestringinfo.string_index;
	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[thestringinfo.string_index]);
	std::cout << std::endl;
	std::cout << std::endl;
}

void Exibidor::displayCONSTANT_Integer_info(CONSTANT_Integer_info & theintinfo){
	std::cout << "\tValue: " << theintinfo.bytes << std::endl;
	std::cout << std::endl;
}

void Exibidor::displayCONSTANT_Float_info(CONSTANT_Float_info & thefloatinfo){
	float buff;
	std::memcpy(&buff, &thefloatinfo.bytes, sizeof(thefloatinfo.bytes));
	std::cout << "\tValue: " << buff << std::endl;
	std::cout << std::endl;
}

void Exibidor::displayCONSTANT_Long_info(CONSTANT_Long_info & thelonginfo){
	uint32_t buff[2];
	std::memcpy(&buff[1], &thelonginfo.high_bytes, sizeof(thelonginfo.high_bytes));
	std::memcpy(&buff[0], &thelonginfo.low_bytes, sizeof(thelonginfo.low_bytes));
	std::cout << "\tValue: " << *((uint64_t*)buff) << std::endl;
	std::cout << std::endl;
}

void Exibidor::displayCONSTANT_Double_info(CONSTANT_Double_info & thedoubleinfo){
	uint32_t buff[2];
	std::memcpy(&buff[1], &thedoubleinfo.high_bytes, sizeof(thedoubleinfo.high_bytes));
	std::memcpy(&buff[0], &thedoubleinfo.low_bytes, sizeof(thedoubleinfo.low_bytes));
	std::cout << "\tHigh bytes: " << std::hex << buff[1] << endl;
	std::cout << "\tLow bytes: " << std::hex << buff[0] << endl;
	std::cout << "\tValue: " << *((double*)buff) << std::endl;
	std::cout << std::endl;
}

void Exibidor::displayconstant_pool(ClassFile & theclass){  // TODO encontrar this class e super class na constant pool para exibir
	/// imprime as entradas.
    std::cout << " Constant Pool:\n";
	for(size_t i = 1; i < theclass.constant_pool_count; i++) {
    	u1 tag;
    	memcpy(&tag, &theclass.constant_pool[i],sizeof(tag));
			std::cout << "  [" << i << std::dec <<  "] ";
    	switch(tag) {
    	case enum_cp_tags::CONSTANT_Class:
				cout << "CONSTANT_Class_info" << std::endl;
    		displayCONSTANT_Class_info(*(CONSTANT_Class_info *)&viewobj.constant_pool[i]);
    		break;
    	case enum_cp_tags::CONSTANT_Fieldref:
    		cout << "CONSTANT_Fieldref_info" << std::endl;
    		displayCONSTANT_Fieldref_info(*(CONSTANT_Fieldref_info *)&viewobj.constant_pool[i]);
        	break;
    	case enum_cp_tags::CONSTANT_Methodref:
    		cout << "CONSTANT_Methodref_info" << std::endl;
    		displayCONSTANT_Methodref_info(*(CONSTANT_Methodref_info *)&viewobj.constant_pool[i]);
    		break;
    	case enum_cp_tags::CONSTANT_InterfaceMethodref:
    		cout << "CONSTANT_InterfaceMethodref_info" << std::endl;
    		displayCONSTANT_InterfaceMethodref_info(*(CONSTANT_InterfaceMethodref_info *)&viewobj.constant_pool[i]);
			break;
    	case enum_cp_tags::CONSTANT_String:
    		cout << "CONSTANT_String_info" << std::endl;
    		displayCONSTANT_String_info(*(CONSTANT_String_info *)&viewobj.constant_pool[i]);
    		break;
    	case enum_cp_tags::CONSTANT_Integer:
    		cout << "CONSTANT_Integer_info" << std::endl;
    		displayCONSTANT_Integer_info(*(CONSTANT_Integer_info *)&viewobj.constant_pool[i]);
    		break;
    	case enum_cp_tags::CONSTANT_Float:
    		cout << "CONSTANT_Float_info" << std::endl;
    		displayCONSTANT_Float_info(*(CONSTANT_Float_info *)&viewobj.constant_pool[i]);
    		break;
    	case enum_cp_tags::CONSTANT_Long:
    		cout << "CONSTANT_Long_info" << std::endl;
    		displayCONSTANT_Long_info(*(CONSTANT_Long_info *)&viewobj.constant_pool[i]);
    		i++;
    		std::cout << "  [" << std::dec << i << "]" << " large numeric continued" << std::endl << std::endl;
    		break;
    	case enum_cp_tags::CONSTANT_Double:
    		cout << "CONSTANT_Double_info" << std::endl;
    		displayCONSTANT_Double_info(*(CONSTANT_Double_info *)&viewobj.constant_pool[i]);
    		i++;
    		std::cout << "  [" << std::dec << i <<  "]" << " large numeric continued" << std::endl << std::endl;
    		break;
    	case enum_cp_tags::CONSTANT_NameAndType:
    		cout << "CONSTANT_NameAndType_info" << std::endl;
    		displayCONSTANT_NameAndType_info(*(CONSTANT_NameAndType_info *)&viewobj.constant_pool[i]);
    		break;
    	case enum_cp_tags::CONSTANT_Utf8:
    		cout << "CONSTANT_Utf8_info" << std::endl;
    		displayCONSTANT_Utf8_info(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[i]);
    		break;
    	default:
    		cout << "broken link" << std::endl;
    		break;
    	}
	}
}


void Exibidor::displayConstantValueAtt(ConstantValue_attribute & theatt, int indent){
	printindent(indent);
	std::cout << "Attribute Name: cp_info# " << std::dec << theatt.attribute_name_index << std::dec << " ";
	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
	std::cout << std::endl;
	printindent(indent);
	std::cout << "Attribute Length: " << std:: dec << theatt.attribute_length << std::endl;
	printindent(indent);
	std::cout << "Value: cp_info# " << theatt.constantvalue_index << std::endl;
	std::cout << std::endl;
}
void Exibidor::displayCodeAtt(Code_attribute & theatt, int indent){
	printindent(indent);
	std::cout << "Attribute Name: cp_info# " << std::dec << theatt.attribute_name_index << std::dec << " ";
	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
	std::cout << std::endl;
	printindent(indent);
	std::cout << "Attribute Length: " << std:: dec << theatt.attribute_length << std::endl;
	printindent(indent);
	std::cout << "Max Stack: " << std::dec << theatt.max_stack << std::endl;
	printindent(indent);
	std::cout << "Max Locals: " << std::dec << theatt.max_locals << std::endl;
	printindent(indent);
	std::cout << "Code Length: " << std::dec << theatt.code_length << std::endl;
	std::cout << std::endl;
	// TODO mostrar codigo
	// TODO mostrat excecoes
	if(theatt.attributes_count > 0){
		displayAttributes(theatt.attributes, theatt.attributes_count, indent+1);
	}
}
void Exibidor::displayDeprecatedAtt(Deprecated_attribute & theatt, int indent){
    printindent(indent);
	std::cout << "Attribute Name: cp_info# " << std::dec << theatt.attribute_name_index << std::dec << " ";
	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
	std::cout << std::endl;
	std::cout << std::endl;
}
void Exibidor::displayExceptionsAtt(Exceptions_attribute & theatt, int indent){
	for(int i=0;i<theatt.number_of_exceptions;i++){
		printindent(indent);
		std::cout << "Exception #" << i << ": ";
		displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theatt.exception_index_table[i]]);
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Exibidor::displayInnerClassesFlags(u2 accflags){
	if (accflags & enum_inner_class_access_flags::ACC_PUBLIC){
		printf("[public]");
	}
	if (accflags & enum_inner_class_access_flags::ACC_PRIVATE){
		printf("[private]");
	}
	if (accflags & enum_inner_class_access_flags::ACC_PROTECTED){
		printf("[protected]");
	}
	if (accflags & enum_inner_class_access_flags::ACC_STATIC){
		printf("[static]");
	}
	if (accflags & enum_inner_class_access_flags::ACC_FINAL){
		printf("[final]");
	}
	if (accflags & enum_inner_class_access_flags::ACC_INTERFACE){
		printf("[interface]");
	}
	if (accflags & enum_inner_class_access_flags::ACC_ABSTRACT){
		printf("[abstract]");
	}
}
void Exibidor::displayInnerClassesAtt(InnerClasses_attribute & theatt, int indent){
	for(int i=0;i<theatt.number_of_classes;i++){
		if(theatt.classes[i].inner_class_info_index != 0){
			printindent(indent);
			std::cout << "Class" << i << ": ";
			displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theatt.classes[i].inner_class_info_index]);
			std::cout << std::endl;
		}
		if(theatt.classes[i].outer_class_info_index != 0){
			printindent(indent);
			std::cout << "Member of: ";
			displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theatt.classes[i].outer_class_info_index]);
			std::cout << std::endl;
		}
		if(theatt.classes[i].inner_name_index != 0){
			printindent(indent);
			std::cout << "Named: ";
			displayClassInfoString(*(CONSTANT_Class_info *)&viewobj.constant_pool[theatt.classes[i].inner_name_index]);
			std::cout << std::endl;
		}
		printindent(indent);
		std::cout << "Access Flags: ";
		displayInnerClassesFlags(theatt.classes[i].inner_class_access_flags);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void Exibidor::displaySourceFileAtt(SourceFile_attribute & theatt, int indent){
	printindent(indent);
	std::cout << "Source: cp_info# " << theatt.sourcefile_index << " ";
	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.sourcefile_index]);
	std::cout << std::endl;
	std::cout << std::endl;
}
void Exibidor::displayLineNumberTableAtt(LineNumberTable_attribute & theatt, int indent){
	
	for(int i=0;i<theatt.line_number_table_length;i++){
		auto aux = theatt.line_number_table[i];
		printindent(indent);std::cout << "Attribute name index: cp_info#" << std::dec  << theatt.attribute_name_index << " ";
		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.attribute_name_index]);
		std::cout << endl;
		printindent(indent);std::cout << "Attribute length: " << std::dec  << theatt.attribute_length << std::endl;		
		printindent(indent);std::cout << "Nr. " << std::dec << i << std::endl;
		printindent(indent);std::cout << "Start PC: " << std::dec << aux.start_pc << std::endl;
		printindent(indent);std::cout << "Line Number: " <<  std::dec << aux.line_number << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl << std::dec;
}
void Exibidor::displayLocalVariableTableAtt(LocalVariableTable_attribute & theatt, int indent){
	for(int i=0;i<theatt.local_variable_table_length;i++){
		printindent(indent);
		std::cout << "Start PC: " << std::dec << std::showbase << theatt.local_variable_table[i].start_pc << std::endl;
		printindent(indent);
		std::cout << "Length: " << std::hex << std::showbase << theatt.local_variable_table[i].length << std::endl << std::dec;
		printindent(indent);
		std::cout << "Name: ";
		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.local_variable_table[i].name_index]);
		std::cout << std::endl;
		printindent(indent);
		std::cout << "Descriptor: ";
		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[theatt.local_variable_table[i].descriptor_index]);
		std::cout << std::endl;
		printindent(indent);
		std::cout << "Variable Index: #" << theatt.local_variable_table[i].index << std::endl;

	}
	std::cout << std::endl;
}
void Exibidor::displayfields(ClassFile & theclass){
    std::cout << " Fields:\n";
	for(size_t i = 0; i < theclass.fields_count; i++) {
    	field_info & aux = theclass.fields[i];
    	std::cout << "  ";
    	std::cout << "[" << i << "]" << " ";
    	displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[aux.name_index]);
    	std::cout << std::endl;
		std::cout << "\tDescriptor: cp_info# " << aux.descriptor_index << " ";
		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[aux.descriptor_index]);
		std::cout << std::endl;
		if(aux.attributes_count > 0){
			displayAttributes(aux.attributes, aux.attributes_count, 3);
		}
	}
}

void Exibidor::displayMethodsFlags(u2 accflags){
	if (accflags & enum_method_access_flags::ACC_PUBLIC){
		printf("[public]");
	}
	if (accflags & enum_method_access_flags::ACC_PRIVATE){
		printf("[private]");
	}
	if (accflags & enum_method_access_flags::ACC_PROTECTED){
		printf("[protected]");
	}
	if (accflags & enum_method_access_flags::ACC_STATIC){
		printf("[static]");
	}
	if (accflags & enum_method_access_flags::ACC_FINAL){
		printf("[final]");
	}
	if (accflags & enum_method_access_flags::ACC_SYNCHRONIZED){
		printf("[synchronized]");
	}
	if (accflags & enum_method_access_flags::ACC_NATIVE){
		printf("[native]");
	}
	if (accflags & enum_method_access_flags::ACC_ABSTRACT){
		printf("[abstract]");
	}
	if (accflags & enum_method_access_flags::ACC_STRICT){
		printf("[strict]");
	}
}
void Exibidor::displaymethods(ClassFile & theclass){
  std::cout << " Methods:\n";
	for(size_t i = 0; i < theclass.methods_count; i++) {
		method_info & aux = theclass.methods[i];
		std::cout << "  ";
		std::cout << "[" << i << "]" << " ";
		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[aux.name_index]);
		std::cout << std::endl;
		std::cout << "\tName: cp_info#" << aux.name_index << " ";
		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[aux.name_index]);
		std::cout << endl;
		std::cout << "\tDescriptor: cp_info# " << aux.descriptor_index << " ";
		displayUtf8InfoString(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[aux.descriptor_index]);
		std::cout << std::endl;
		std::cout << "\tAccess Flags: " << std::hex << aux.access_flags;
		displayMethodsFlags(aux.access_flags);
		std::cout << std::endl;
		if(aux.attributes_count > 0){
			displayAttributes(aux.attributes, aux.attributes_count, 3);
		}
	}
}
att_name_result Exibidor::attributenamecompare(CONSTANT_Utf8_info & name){
	int size = name.length+1;
	int i;
	char namestring[size];
	for (i=0; i<name.length; i++){
		namestring[i] = (char)name.bytes[i];
	}
	namestring[i]='\0';
	if (std::strcmp(namestring, "ConstantValue")==0){
		return ATT_CONSTANTVALUE;
	}
	if (std::strcmp(namestring, "Code")==0){
		return ATT_CODE;
	}
	if (std::strcmp(namestring, "Deprecated")==0){
		return ATT_DEPRECATED;
	}
	if (std::strcmp(namestring, "Exceptions")==0){
		return ATT_EXCEPTIONS;
	}
	if (std::strcmp(namestring, "InnerClasses")==0){
		return ATT_INNERCLASSES;
	}
	if (std::strcmp(namestring, "SourceFile")==0){
		return ATT_SOURCEFILE;
	}
	if (std::strcmp(namestring, "LineNumberTable")==0){
		return ATT_LINENUMBERTABLE;
	}
	if (std::strcmp(namestring, "LocalVariableTable")==0){
		return ATT_LOCALVARIABLETABLE;
	}
	if (std::strcmp(namestring, "Synthetic")==0){
		return ATT_SYNTHETIC;
	}
	else return ATT_INVALID;
}
void Exibidor::printindent(int indent){
	for(int i=0; i<indent; i++){
		printf(" ");
	}
}
void Exibidor::displayAttributes(attribute_info * attlist, int length, int indent){
    printindent(indent);
    std::cout << "Attributes:" << std::endl;
	for(int i=0; i<length; i++){
    	u2 tag;
    	memcpy(&tag, &attlist[i],sizeof(tag));
			printindent(indent);
			std::cout << "Attribute name index: cp_info#" << std::dec << tag << " ";
    	int nameswitch = attributenamecompare(*(CONSTANT_Utf8_info *)&viewobj.constant_pool[tag]);

    	switch(nameswitch) {
				case ATT_CONSTANTVALUE:cout<<"<ConstantValue>"<<std::endl;break;
				case ATT_CODE:cout<<"<Code>"<<std::endl;break;
				case ATT_DEPRECATED:cout<<"<Deprecated>"<<std::endl;break;
				case ATT_EXCEPTIONS:cout<<"<Exceptions>"<<std::endl;break;
				case ATT_INNERCLASSES:cout<<"<InnerClasses>"<<std::endl;break;
				case ATT_SOURCEFILE:cout<<"<SourceFile>"<<std::endl;break;
				case ATT_LINENUMBERTABLE:cout<<"<LineNumberTable>"<<std::endl;break;
				case ATT_LOCALVARIABLETABLE:cout<<"<LocalVariableTable>"<<std::endl;break;
				default:cout<<"<invalid attribute>"<<std::endl;break;
    	}

			auto aux = *(CONSTANT_Utf8_info *)&viewobj.constant_pool[tag];
			// std::cout << "Attribute length: "  << std::endl;
			// std::cout << "Attribute length: cp_info#" << std::dec << viewobj << std::endl;
			printindent(indent);
			std::cout << "[" << i << "] ";
    	switch(nameswitch) {
				case ATT_CONSTANTVALUE:    		
					cout << "ConstantValue" << std::endl;
					displayConstantValueAtt(*(ConstantValue_attribute *)&attlist[i], indent+1);
					break;
				case ATT_CODE:
					cout << "Code" << std::endl;
					displayCodeAtt(*(Code_attribute *)&attlist[i], indent+1);
						break;
				case ATT_DEPRECATED:
					cout << "Deprecated" << std::endl;
					displayDeprecatedAtt(*(Deprecated_attribute *)&attlist[i], indent+1);
					break;
				case ATT_EXCEPTIONS:
					cout << "Exceptions" << std::endl;
					displayExceptionsAtt(*(Exceptions_attribute *)&attlist[i], indent+1);
				break;
				case ATT_INNERCLASSES:
					cout << "InnerClasses" << std::endl;
					displayInnerClassesAtt(*(InnerClasses_attribute *)&attlist[i], indent+1);
					break;
				case ATT_SOURCEFILE:
					cout << "SourceFile" << std::endl;
					displaySourceFileAtt(*(SourceFile_attribute *)&attlist[i], indent+1);
					break;
				case ATT_LINENUMBERTABLE:
					cout << "LineNumberTable" << std::endl;
					displayLineNumberTableAtt(*(LineNumberTable_attribute *)&attlist[i], indent+1);
					break;
				case ATT_LOCALVARIABLETABLE:
					cout << "LocalVariableTable" << std::endl;
					displayLocalVariableTableAtt(*(LocalVariableTable_attribute *)&attlist[i], indent+1);
					break;
				default:
					cout << "invalid attribute" << std::endl;
					break;
    	}
	}
}

void Exibidor::control_class(){
	displayClassFile(viewobj);
	control_cp();
	if(viewobj.fields_count > 0){
		control_fields();
	}
	if(viewobj.methods_count > 0){
		control_methods();
	}
	if(viewobj.attributes_count > 0){
		displayAttributes(viewobj.attributes, viewobj.attributes_count, 1);
	}
}
void Exibidor::control_cp(){
	displayconstant_pool(viewobj);
}
void Exibidor::control_fields(){
	displayfields(viewobj);
}
void Exibidor::control_methods(){
	displaymethods(viewobj);
}
void Exibidor::control_attributes(){}
void Exibidor::feed(ClassFile toshow){
	viewobj = toshow;
}
void Exibidor::show(){
	control_class();
}