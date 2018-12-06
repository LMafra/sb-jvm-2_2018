#include <iostream>

enum Constants{
  nop = 0,
  aconst_null, iconst_m1, iconst_0, iconst_1, iconst_2, iconst_3, iconst_4, iconst_5,
  lconst_0, lconst_1, fconst_0, fconst_1, fconst_2, dconst_0, dconst_1,
  bipush, sipush, ldc, ldc_w, ldc2_w
};

enum Loads{
  iload = 21,
  lload, fload, dload, aload, iload_0, iload_1, iload_2, iload_3, lload_0, lload_1, lload_2, lload_3,
  fload_0, fload_1, fload_2, fload_3, dload_0, dload_1, dload_2, dload_3, aload_0, aload_1, aload_2,
  aload_3, iaload, faload, daload, aaload, baload, caload, saload
};

enum Stores{
  istore = 54,
  lstore, fstore, dstore, astore, istore_0, istore_1, istore_2, istore_3, lstore_0, lstore_1, lstore_2, lstore_3,
  fstore_0, fstore_1, fstore_2, fstore_3, dstore_0, dstore_1, dstore_2, dstore_3, astore_0, astore_1, astore_2,
  astore_3, iastore, lastore, fastore, dastore, aastore, bastore, castore, sastore
};

enum Stack{
  pop = 87,
  pop2, dup, dup_x1, dup_x2, dup2, dup2_x1, dup2_x2, swap
};

enum Math{
  iadd = 96;
  ladd, fadd, dadd, isub, lsub, fsub, dsub, imul, lmul, fmul, dmul, idiv, ldiv, fdiv, ddiv, irem, lrem,
  frem, drem, ineg, lneg, fneg, dneg, ishl, lshl, ishr, lshr, iushr, lushr, iand, land, ior, lor, ixor, lxor, iinc
};

enum Conversions{
  i2l = 133;
  i2f, i2d, l2i, l2f, l2d, f2i, f2l, f2d, d2i, d2l, d2f, i2b, i2c, i2s
};

enum Comparisons{
  lcmp = 148,
  fcmpl, fcmpg, dcmpl, dcmpg, ifeq, ifne, iflt, ifge, ifgt, ifle, if_icmpeq, if_icmpne, if_icmplt, if_icmpge,
  if_icmpgt, if_icmple, if_acmpeq, if_acmpne
};

enum Control{
  goto = 167,
  jsr, ret, tableswitch, lookupswitch, ireturn, lreturn, freturn, dreturn, areturn, return
};

enum References{
  getstatic = 178,
  putstatic, getfield, putfield, invokevirtual, invokespecial, invokestatic, invokeinterface, invokedynamic,
  new, newarray, anewarray, arraylength, athrow, checkcast, instanceof, monitorenter, monitorexit
};

enum Extended{
  wide = 196,
  multianewarray, ifnull, ifnonnull, goto_w, jsr_w
};

enum Reserved{
  breakpoint = 202,
  impdep1 = 254,
  impdep2
};


void print_instruction(u1 *, int *){
  enum Constants, Loads, Stores, Stack, Math,
  Conversions, Comparisons, Control, References, Extended, Reserved;

  switch(opcode){
  case 0:
  /*Stuff*/

  break;
  case 1:
  /*Stuff*/

  break;
  case 2:
  /*Stuff*/

  break;
  case 3:
  /*Stuff*/

  break;
  case 4:
  /*Stuff*/

  break;
  case 5:
  /*Stuff*/

  break;
  case 6:
  /*Stuff*/

  break;
  case 7:
  /*Stuff*/

  break;
  case 8:
  /*Stuff*/

  break;
  case 9:
  /*Stuff*/

  break;
  case 10:
  /*Stuff*/

  break;
  case 11:
  /*Stuff*/

  break;
  case 12:
  /*Stuff*/

  break;
  case 13:
  /*Stuff*/

  break;
  case 14:
  /*Stuff*/

  break;
  case 15:
  /*Stuff*/

  break;
  case 16:
  /*Stuff*/

  break;
  case 17:
  /*Stuff*/

  break;
  case 18:
  /*Stuff*/

  break;
  case 19:
  /*Stuff*/

  break;
  case 20:
  /*Stuff*/

  break;
  case 21:
  /*Stuff*/

  break;
  case 22:
  /*Stuff*/

  break;
  case 23:
  /*Stuff*/

  break;
  case 24:
  /*Stuff*/

  break;
  case 25:
  /*Stuff*/

  break;
  case 26:
  /*Stuff*/

  break;
  case 27:
  /*Stuff*/

  break;
  case 28:
  /*Stuff*/

  break;
  case 29:
  /*Stuff*/

  break;
  case 30:
  /*Stuff*/

  break;
  case 31:
  /*Stuff*/

  break;
  case 32:
  /*Stuff*/

  break;
  case 33:
  /*Stuff*/

  break;
  case 34:
  /*Stuff*/

  break;
  case 35:
  /*Stuff*/

  break;
  case 36:
  /*Stuff*/

  break;
  case 37:
  /*Stuff*/

  break;
  case 38:
  /*Stuff*/

  break;
  case 39:
  /*Stuff*/

  break;
  case 40:
  /*Stuff*/

  break;
  case 41:
  /*Stuff*/

  break;
  case 42:
  /*Stuff*/

  break;
  case 43:
  /*Stuff*/

  break;
  case 44:
  /*Stuff*/

  break;
  case 45:
  /*Stuff*/

  break;
  case 46:
  /*Stuff*/

  break;
  case 47:
  /*Stuff*/

  break;
  case 48:
  /*Stuff*/

  break;
  case 49:
  /*Stuff*/

  break;
  case 50:
  /*Stuff*/

  break;
  case 51:
  /*Stuff*/

  break;
  case 52:
  /*Stuff*/

  break;
  case 53:
  /*Stuff*/

  break;
  case 54:
  /*Stuff*/

  break;
  case 55:
  /*Stuff*/

  break;
  case 56:
  /*Stuff*/

  break;
  case 57:
  /*Stuff*/

  break;
  case 58:
  /*Stuff*/

  break;
  case 59:
  /*Stuff*/

  break;
  case 60:
  /*Stuff*/

  break;
  case 61:
  /*Stuff*/

  break;
  case 62:
  /*Stuff*/

  break;
  case 63:
  /*Stuff*/

  break;
  case 64:
  /*Stuff*/

  break;
  case 65:
  /*Stuff*/

  break;
  case 66:
  /*Stuff*/

  break;
  case 67:
  /*Stuff*/

  break;
  case 68:
  /*Stuff*/

  break;
  case 69:
  /*Stuff*/

  break;
  case 70:
  /*Stuff*/

  break;
  case 71:
  /*Stuff*/

  break;
  case 72:
  /*Stuff*/

  break;
  case 73:
  /*Stuff*/

  break;
  case 74:
  /*Stuff*/

  break;
  case 75:
  /*Stuff*/

  break;
  case 76:
  /*Stuff*/

  break;
  case 77:
  /*Stuff*/

  break;
  case 78:
  /*Stuff*/

  break;
  case 79:
  /*Stuff*/

  break;
  case 80:
  /*Stuff*/

  break;
  case 81:
  /*Stuff*/

  break;
  case 82:
  /*Stuff*/

  break;
  case 83:
  /*Stuff*/

  break;
  case 84:
  /*Stuff*/

  break;
  case 85:
  /*Stuff*/

  break;
  case 86:
  /*Stuff*/

  break;
  case 87:
  /*Stuff*/

  break;
  case 88:
  /*Stuff*/

  break;
  case 89:
  /*Stuff*/

  break;
  case 90:
  /*Stuff*/

  break;
  case 91:
  /*Stuff*/

  break;
  case 92:
  /*Stuff*/

  break;
  case 93:
  /*Stuff*/

  break;
  case 94:
  /*Stuff*/

  break;
  case 95:
  /*Stuff*/

  break;
  case 96:
  /*Stuff*/

  break;
  case 97:
  /*Stuff*/

  break;
  case 98:
  /*Stuff*/

  break;
  case 99:
  /*Stuff*/

  break;
  case 100:
  /*Stuff*/

  break;
  case 101:
  /*Stuff*/

  break;
  case 102:
  /*Stuff*/

  break;
  case 103:
  /*Stuff*/

  break;
  case 104:
  /*Stuff*/

  break;
  case 105:
  /*Stuff*/

  break;
  case 106:
  /*Stuff*/

  break;
  case 107:
  /*Stuff*/

  break;
  case 108:
  /*Stuff*/

  break;
  case 109:
  /*Stuff*/

  break;
  case 110:
  /*Stuff*/

  break;
  case 111:
  /*Stuff*/

  break;
  case 112:
  /*Stuff*/

  break;
  case 113:
  /*Stuff*/

  break;
  case 114:
  /*Stuff*/

  break;
  case 115:
  /*Stuff*/

  break;
  case 116:
  /*Stuff*/

  break;
  case 117:
  /*Stuff*/

  break;
  case 118:
  /*Stuff*/

  break;
  case 119:
  /*Stuff*/

  break;
  case 120:
  /*Stuff*/

  break;
  case 121:
  /*Stuff*/

  break;
  case 122:
  /*Stuff*/

  break;
  case 123:
  /*Stuff*/

  break;
  case 124:
  /*Stuff*/

  break;
  case 125:
  /*Stuff*/

  break;
  case 126:
  /*Stuff*/

  break;
  case 127:
  /*Stuff*/

  break;
  case 128:
  /*Stuff*/

  break;
  case 129:
  /*Stuff*/

  break;
  case 130:
  /*Stuff*/

  break;
  case 131:
  /*Stuff*/

  break;
  case 132:
  /*Stuff*/

  break;
  case 133:
  /*Stuff*/

  break;
  case 134:
  /*Stuff*/

  break;
  case 135:
  /*Stuff*/

  break;
  case 136:
  /*Stuff*/

  break;
  case 137:
  /*Stuff*/

  break;
  case 138:
  /*Stuff*/

  break;
  case 139:
  /*Stuff*/

  break;
  case 140:
  /*Stuff*/

  break;
  case 141:
  /*Stuff*/

  break;
  case 142:
  /*Stuff*/

  break;
  case 143:
  /*Stuff*/

  break;
  case 144:
  /*Stuff*/

  break;
  case 145:
  /*Stuff*/

  break;
  case 146:
  /*Stuff*/

  break;
  case 147:
  /*Stuff*/

  break;
  case 148:
  /*Stuff*/

  break;
  case 149:
  /*Stuff*/

  break;
  case 150:
  /*Stuff*/

  break;
  case 151:
  /*Stuff*/

  break;
  case 152:
  /*Stuff*/

  break;
  case 153:
  /*Stuff*/

  break;
  case 154:
  /*Stuff*/

  break;
  case 155:
  /*Stuff*/

  break;
  case 156:
  /*Stuff*/

  break;
  case 157:
  /*Stuff*/

  break;
  case 158:
  /*Stuff*/

  break;
  case 159:
  /*Stuff*/

  break;
  case 160:
  /*Stuff*/

  break;
  case 161:
  /*Stuff*/

  break;
  case 162:
  /*Stuff*/

  break;
  case 163:
  /*Stuff*/

  break;
  case 164:
  /*Stuff*/

  break;
  case 165:
  /*Stuff*/

  break;
  case 166:
  /*Stuff*/

  break;
  case 167:
  /*Stuff*/

  break;
  case 168:
  /*Stuff*/

  break;
  case 169:
  /*Stuff*/

  break;
  case 170:
  /*Stuff*/

  break;
  case 171:
  /*Stuff*/

  break;
  case 172:
  /*Stuff*/

  break;
  case 173:
  /*Stuff*/

  break;
  case 174:
  /*Stuff*/

  break;
  case 175:
  /*Stuff*/

  break;
  case 176:
  /*Stuff*/

  break;
  case 177:
  /*Stuff*/

  break;
  case 178:
  /*Stuff*/

  break;
  case 179:
  /*Stuff*/

  break;
  case 180:
  /*Stuff*/

  break;
  case 181:
  /*Stuff*/

  break;
  case 182:
  /*Stuff*/

  break;
  case 183:
  /*Stuff*/

  break;
  case 184:
  /*Stuff*/

  break;
  case 185:
  /*Stuff*/

  break;
  case 186:
  /*Stuff*/

  break;
  case 187:
  /*Stuff*/

  break;
  case 188:
  /*Stuff*/

  break;
  case 189:
  /*Stuff*/

  break;
  case 190:
  /*Stuff*/

  break;
  case 191:
  /*Stuff*/

  break;
  case 192:
  /*Stuff*/

  break;
  case 193:
  /*Stuff*/

  break;
  case 194:
  /*Stuff*/

  break;
  case 195:
  /*Stuff*/

  break;
  case 196:
  /*Stuff*/

  break;
  case 197:
  /*Stuff*/

  break;
  case 198:
  /*Stuff*/

  break;
  case 199:
  /*Stuff*/

  break;
  case 200:
  /*Stuff*/

  break;
  case 201:
  /*Stuff*/

  break;
  case 202:
  /*Stuff*/

  break;
  case 203:
  /*Stuff*/

  break;
  case 204:
  /*Stuff*/

  break;
  case 205:
  /*Stuff*/

  break;
  case 206:
  /*Stuff*/

  break;
  case 207:
  /*Stuff*/

  break;
  case 208:
  /*Stuff*/

  break;
  case 209:
  /*Stuff*/

  break;
  case 210:
  /*Stuff*/

  break;
  case 211:
  /*Stuff*/

  break;
  case 212:
  /*Stuff*/

  break;
  case 213:
  /*Stuff*/

  break;
  case 214:
  /*Stuff*/

  break;
  case 215:
  /*Stuff*/

  break;
  case 216:
  /*Stuff*/

  break;
  case 217:
  /*Stuff*/

  break;
  case 218:
  /*Stuff*/

  break;
  case 219:
  /*Stuff*/

  break;
  case 220:
  /*Stuff*/

  break;
  case 221:
  /*Stuff*/

  break;
  case 222:
  /*Stuff*/

  break;
  case 223:
  /*Stuff*/

  break;
  case 224:
  /*Stuff*/

  break;
  case 225:
  /*Stuff*/

  break;
  case 226:
  /*Stuff*/

  break;
  case 227:
  /*Stuff*/

  break;
  case 228:
  /*Stuff*/

  break;
  case 229:
  /*Stuff*/

  break;
  case 230:
  /*Stuff*/

  break;
  case 231:
  /*Stuff*/

  break;
  case 232:
  /*Stuff*/

  break;
  case 233:
  /*Stuff*/

  break;
  case 234:
  /*Stuff*/

  break;
  case 235:
  /*Stuff*/

  break;
  case 236:
  /*Stuff*/

  break;
  case 237:
  /*Stuff*/

  break;
  case 238:
  /*Stuff*/

  break;
  case 239:
  /*Stuff*/

  break;
  case 240:
  /*Stuff*/

  break;
  case 241:
  /*Stuff*/

  break;
  case 242:
  /*Stuff*/

  break;
  case 243:
  /*Stuff*/

  break;
  case 244:
  /*Stuff*/

  break;
  case 245:
  /*Stuff*/

  break;
  case 246:
  /*Stuff*/

  break;
  case 247:
  /*Stuff*/

  break;
  case 248:
  /*Stuff*/

  break;
  case 249:
  /*Stuff*/

  break;

  }
}