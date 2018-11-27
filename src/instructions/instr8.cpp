void exec_jvm_if_acmpne(){

}

void exec_jvm_goto(){
    u1 offset1 = frame->code[frame->pc +1];
    u1 offset2 = frame->code[frame->pc +2];

    u2 offset = offset1;
    offset <<= 8;
    offset |= offset2; 

    frame->pc += offset;
}

void exec_jvm_jsr(){

}
void exec_jvm_ret(){

}
void exec_jvm_tableswitch(){

}
void exec_jvm_lookupswitch(){

}
void exec_jvm_ireturn(){

}
void exec_jvm_lreturn(){

}
void exec_jvm_freturn(){

}
void exec_jvm_dreturn(){

}
void exec_jvm_areturn(){

}
void exec_jvm_return(){

}
void exec_jvm_getstatic(){

}
void exec_jvm_putstatic(){

}
void exec_jvm_getfield(){

}
void exec_jvm_putfield(){

}
void exec_jvm_invokevirtual(){

}
void exec_jvm_invokespecial(){

}
void exec_jvm_invokestatic(){

}
void exec_jvm_invokeinterface(){

}
void exec_jvm_invokedynamic(){

}