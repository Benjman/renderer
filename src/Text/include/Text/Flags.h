#ifndef TEXT_FLAGS_H
#define TEXT_FLAGS_H

#include <cstdint>

#define TEXT_ALIGN_BITS (2)
#define TEXT_ALIGN_SHIFT (0)
#define TEXT_ALIGN_MASK (0x3)

#define LINE_GAP_BITS (3)
#define LINE_GAP_SHIFT (TEXT_ALIGN_SHIFT + TEXT_ALIGN_BITS)
#define LINE_GAP_MASK (0x7)

#define TEXT_SIZE_BITS (8)
#define TEXT_SIZE_SHIFT (LINE_GAP_SHIFT + LINE_GAP_BITS)
#define TEXT_SIZE_MASK (0xff)


// TEXT_ALIGN_* mask is 2 bits; 4 values max
extern const uint32_t TEXT_ALIGN_LEFT;
extern const uint32_t TEXT_ALIGN_RIGHT;
extern const uint32_t TEXT_ALIGN_CENTER;
extern const uint32_t TEXT_ALIGN_JUSTIFY;

// LINE_GAP_* mask is 3 bits; 8 values max
extern const uint32_t LINE_GAP_1_0;
extern const uint32_t LINE_GAP_1_15;
extern const uint32_t LINE_GAP_1_5;
extern const uint32_t LINE_GAP_2_0;

// TEXT_SIZE_* mask is 8 bits, 256 values
extern const uint32_t TEXT_SIZE_4;
extern const uint32_t TEXT_SIZE_5;
extern const uint32_t TEXT_SIZE_6;
extern const uint32_t TEXT_SIZE_7;
extern const uint32_t TEXT_SIZE_8;
extern const uint32_t TEXT_SIZE_9;
extern const uint32_t TEXT_SIZE_10;
extern const uint32_t TEXT_SIZE_11;
extern const uint32_t TEXT_SIZE_12;
extern const uint32_t TEXT_SIZE_13;
extern const uint32_t TEXT_SIZE_14;
extern const uint32_t TEXT_SIZE_15;
extern const uint32_t TEXT_SIZE_16;
extern const uint32_t TEXT_SIZE_17;
extern const uint32_t TEXT_SIZE_18;
extern const uint32_t TEXT_SIZE_19;
extern const uint32_t TEXT_SIZE_20;
extern const uint32_t TEXT_SIZE_21;
extern const uint32_t TEXT_SIZE_22;
extern const uint32_t TEXT_SIZE_23;
extern const uint32_t TEXT_SIZE_24;
extern const uint32_t TEXT_SIZE_25;
extern const uint32_t TEXT_SIZE_26;
extern const uint32_t TEXT_SIZE_27;
extern const uint32_t TEXT_SIZE_28;
extern const uint32_t TEXT_SIZE_29;
extern const uint32_t TEXT_SIZE_30;
extern const uint32_t TEXT_SIZE_31;
extern const uint32_t TEXT_SIZE_32;
extern const uint32_t TEXT_SIZE_33;
extern const uint32_t TEXT_SIZE_34;
extern const uint32_t TEXT_SIZE_35;
extern const uint32_t TEXT_SIZE_36;
extern const uint32_t TEXT_SIZE_37;
extern const uint32_t TEXT_SIZE_38;
extern const uint32_t TEXT_SIZE_39;
extern const uint32_t TEXT_SIZE_40;
extern const uint32_t TEXT_SIZE_41;
extern const uint32_t TEXT_SIZE_42;
extern const uint32_t TEXT_SIZE_43;
extern const uint32_t TEXT_SIZE_44;
extern const uint32_t TEXT_SIZE_45;
extern const uint32_t TEXT_SIZE_46;
extern const uint32_t TEXT_SIZE_47;
extern const uint32_t TEXT_SIZE_48;
extern const uint32_t TEXT_SIZE_49;
extern const uint32_t TEXT_SIZE_50;
extern const uint32_t TEXT_SIZE_51;
extern const uint32_t TEXT_SIZE_52;
extern const uint32_t TEXT_SIZE_53;
extern const uint32_t TEXT_SIZE_54;
extern const uint32_t TEXT_SIZE_55;
extern const uint32_t TEXT_SIZE_56;
extern const uint32_t TEXT_SIZE_57;
extern const uint32_t TEXT_SIZE_58;
extern const uint32_t TEXT_SIZE_59;
extern const uint32_t TEXT_SIZE_60;
extern const uint32_t TEXT_SIZE_61;
extern const uint32_t TEXT_SIZE_62;
extern const uint32_t TEXT_SIZE_63;
extern const uint32_t TEXT_SIZE_64;
extern const uint32_t TEXT_SIZE_65;
extern const uint32_t TEXT_SIZE_66;
extern const uint32_t TEXT_SIZE_67;
extern const uint32_t TEXT_SIZE_68;
extern const uint32_t TEXT_SIZE_69;
extern const uint32_t TEXT_SIZE_70;
extern const uint32_t TEXT_SIZE_71;
extern const uint32_t TEXT_SIZE_72;
extern const uint32_t TEXT_SIZE_73;
extern const uint32_t TEXT_SIZE_74;
extern const uint32_t TEXT_SIZE_75;
extern const uint32_t TEXT_SIZE_76;
extern const uint32_t TEXT_SIZE_77;
extern const uint32_t TEXT_SIZE_78;
extern const uint32_t TEXT_SIZE_79;
extern const uint32_t TEXT_SIZE_80;
extern const uint32_t TEXT_SIZE_81;
extern const uint32_t TEXT_SIZE_82;
extern const uint32_t TEXT_SIZE_83;
extern const uint32_t TEXT_SIZE_84;
extern const uint32_t TEXT_SIZE_85;
extern const uint32_t TEXT_SIZE_86;
extern const uint32_t TEXT_SIZE_87;
extern const uint32_t TEXT_SIZE_88;
extern const uint32_t TEXT_SIZE_89;
extern const uint32_t TEXT_SIZE_90;
extern const uint32_t TEXT_SIZE_91;
extern const uint32_t TEXT_SIZE_92;
extern const uint32_t TEXT_SIZE_93;
extern const uint32_t TEXT_SIZE_94;
extern const uint32_t TEXT_SIZE_95;
extern const uint32_t TEXT_SIZE_96;
extern const uint32_t TEXT_SIZE_97;
extern const uint32_t TEXT_SIZE_98;
extern const uint32_t TEXT_SIZE_99;
extern const uint32_t TEXT_SIZE_100;
extern const uint32_t TEXT_SIZE_101;
extern const uint32_t TEXT_SIZE_102;
extern const uint32_t TEXT_SIZE_103;
extern const uint32_t TEXT_SIZE_104;
extern const uint32_t TEXT_SIZE_105;
extern const uint32_t TEXT_SIZE_106;
extern const uint32_t TEXT_SIZE_107;
extern const uint32_t TEXT_SIZE_108;
extern const uint32_t TEXT_SIZE_109;
extern const uint32_t TEXT_SIZE_110;
extern const uint32_t TEXT_SIZE_111;
extern const uint32_t TEXT_SIZE_112;
extern const uint32_t TEXT_SIZE_113;
extern const uint32_t TEXT_SIZE_114;
extern const uint32_t TEXT_SIZE_115;
extern const uint32_t TEXT_SIZE_116;
extern const uint32_t TEXT_SIZE_117;
extern const uint32_t TEXT_SIZE_118;
extern const uint32_t TEXT_SIZE_119;
extern const uint32_t TEXT_SIZE_120;
extern const uint32_t TEXT_SIZE_121;
extern const uint32_t TEXT_SIZE_122;
extern const uint32_t TEXT_SIZE_123;
extern const uint32_t TEXT_SIZE_124;
extern const uint32_t TEXT_SIZE_125;
extern const uint32_t TEXT_SIZE_126;
extern const uint32_t TEXT_SIZE_127;
extern const uint32_t TEXT_SIZE_128;
extern const uint32_t TEXT_SIZE_129;
extern const uint32_t TEXT_SIZE_130;
extern const uint32_t TEXT_SIZE_131;
extern const uint32_t TEXT_SIZE_132;
extern const uint32_t TEXT_SIZE_133;
extern const uint32_t TEXT_SIZE_134;
extern const uint32_t TEXT_SIZE_135;
extern const uint32_t TEXT_SIZE_136;
extern const uint32_t TEXT_SIZE_137;
extern const uint32_t TEXT_SIZE_138;
extern const uint32_t TEXT_SIZE_139;
extern const uint32_t TEXT_SIZE_140;
extern const uint32_t TEXT_SIZE_141;
extern const uint32_t TEXT_SIZE_142;
extern const uint32_t TEXT_SIZE_143;
extern const uint32_t TEXT_SIZE_144;
extern const uint32_t TEXT_SIZE_145;
extern const uint32_t TEXT_SIZE_146;
extern const uint32_t TEXT_SIZE_147;
extern const uint32_t TEXT_SIZE_148;
extern const uint32_t TEXT_SIZE_149;
extern const uint32_t TEXT_SIZE_150;
extern const uint32_t TEXT_SIZE_151;
extern const uint32_t TEXT_SIZE_152;
extern const uint32_t TEXT_SIZE_153;
extern const uint32_t TEXT_SIZE_154;
extern const uint32_t TEXT_SIZE_155;
extern const uint32_t TEXT_SIZE_156;
extern const uint32_t TEXT_SIZE_157;
extern const uint32_t TEXT_SIZE_158;
extern const uint32_t TEXT_SIZE_159;
extern const uint32_t TEXT_SIZE_160;
extern const uint32_t TEXT_SIZE_161;
extern const uint32_t TEXT_SIZE_162;
extern const uint32_t TEXT_SIZE_163;
extern const uint32_t TEXT_SIZE_164;
extern const uint32_t TEXT_SIZE_165;
extern const uint32_t TEXT_SIZE_166;
extern const uint32_t TEXT_SIZE_167;
extern const uint32_t TEXT_SIZE_168;
extern const uint32_t TEXT_SIZE_169;
extern const uint32_t TEXT_SIZE_170;
extern const uint32_t TEXT_SIZE_171;
extern const uint32_t TEXT_SIZE_172;
extern const uint32_t TEXT_SIZE_173;
extern const uint32_t TEXT_SIZE_174;
extern const uint32_t TEXT_SIZE_175;
extern const uint32_t TEXT_SIZE_176;
extern const uint32_t TEXT_SIZE_177;
extern const uint32_t TEXT_SIZE_178;
extern const uint32_t TEXT_SIZE_179;
extern const uint32_t TEXT_SIZE_180;
extern const uint32_t TEXT_SIZE_181;
extern const uint32_t TEXT_SIZE_182;
extern const uint32_t TEXT_SIZE_183;
extern const uint32_t TEXT_SIZE_184;
extern const uint32_t TEXT_SIZE_185;
extern const uint32_t TEXT_SIZE_186;
extern const uint32_t TEXT_SIZE_187;
extern const uint32_t TEXT_SIZE_188;
extern const uint32_t TEXT_SIZE_189;
extern const uint32_t TEXT_SIZE_190;
extern const uint32_t TEXT_SIZE_191;
extern const uint32_t TEXT_SIZE_192;
extern const uint32_t TEXT_SIZE_193;
extern const uint32_t TEXT_SIZE_194;
extern const uint32_t TEXT_SIZE_195;
extern const uint32_t TEXT_SIZE_196;
extern const uint32_t TEXT_SIZE_197;
extern const uint32_t TEXT_SIZE_198;
extern const uint32_t TEXT_SIZE_199;
extern const uint32_t TEXT_SIZE_200;
extern const uint32_t TEXT_SIZE_201;
extern const uint32_t TEXT_SIZE_202;
extern const uint32_t TEXT_SIZE_203;
extern const uint32_t TEXT_SIZE_204;
extern const uint32_t TEXT_SIZE_205;
extern const uint32_t TEXT_SIZE_206;
extern const uint32_t TEXT_SIZE_207;
extern const uint32_t TEXT_SIZE_208;
extern const uint32_t TEXT_SIZE_209;
extern const uint32_t TEXT_SIZE_210;
extern const uint32_t TEXT_SIZE_211;
extern const uint32_t TEXT_SIZE_212;
extern const uint32_t TEXT_SIZE_213;
extern const uint32_t TEXT_SIZE_214;
extern const uint32_t TEXT_SIZE_215;
extern const uint32_t TEXT_SIZE_216;
extern const uint32_t TEXT_SIZE_217;
extern const uint32_t TEXT_SIZE_218;
extern const uint32_t TEXT_SIZE_219;
extern const uint32_t TEXT_SIZE_220;
extern const uint32_t TEXT_SIZE_221;
extern const uint32_t TEXT_SIZE_222;
extern const uint32_t TEXT_SIZE_223;
extern const uint32_t TEXT_SIZE_224;
extern const uint32_t TEXT_SIZE_225;
extern const uint32_t TEXT_SIZE_226;
extern const uint32_t TEXT_SIZE_227;
extern const uint32_t TEXT_SIZE_228;
extern const uint32_t TEXT_SIZE_229;
extern const uint32_t TEXT_SIZE_230;
extern const uint32_t TEXT_SIZE_231;
extern const uint32_t TEXT_SIZE_232;
extern const uint32_t TEXT_SIZE_233;
extern const uint32_t TEXT_SIZE_234;
extern const uint32_t TEXT_SIZE_235;
extern const uint32_t TEXT_SIZE_236;
extern const uint32_t TEXT_SIZE_237;
extern const uint32_t TEXT_SIZE_238;
extern const uint32_t TEXT_SIZE_239;
extern const uint32_t TEXT_SIZE_240;
extern const uint32_t TEXT_SIZE_241;
extern const uint32_t TEXT_SIZE_242;
extern const uint32_t TEXT_SIZE_243;
extern const uint32_t TEXT_SIZE_244;
extern const uint32_t TEXT_SIZE_245;
extern const uint32_t TEXT_SIZE_246;
extern const uint32_t TEXT_SIZE_247;
extern const uint32_t TEXT_SIZE_248;
extern const uint32_t TEXT_SIZE_249;
extern const uint32_t TEXT_SIZE_250;
extern const uint32_t TEXT_SIZE_251;
extern const uint32_t TEXT_SIZE_252;
extern const uint32_t TEXT_SIZE_253;
extern const uint32_t TEXT_SIZE_254;
extern const uint32_t TEXT_SIZE_255;

#endif // TEXT_FLAGS_H
