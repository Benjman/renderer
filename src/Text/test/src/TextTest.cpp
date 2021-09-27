#include "utils/glfw.h"

#include <gtest/gtest.h>
#include <cmath>
#include <GLFW/glfw3.h>

#include <Text/Font.h>

#define private public
#include <Text/Text.h>

class TextFixture : public ::testing::Test {
	protected:
		static void SetUpTestSuite() {
			load_font(font, "/home/ben/src/renderer/res/fonts/DejaVuSans.ttf", false);
		}

		static void TearDownTestSuite() {
		}

		static Font font;
		static Text text;
};

Font TextFixture::font = Font();
Text TextFixture::text = Text("", &font, glm::vec2(), 0);

TEST_F(TextFixture, flags_test) {
	text.set_flags(TEXT_ALIGN_JUSTIFY |
			LINE_GAP_2_0 |
			TEXT_SIZE_255 |
			DISPLAY_PROFILE_3840_2160);

	ASSERT_EQ(TEXT_ALIGN_JUSTIFY, text.flags & TEXT_ALIGN_MASK);
	ASSERT_EQ(LINE_GAP_2_0, text.flags & LINE_GAP_MASK);
	ASSERT_EQ(TEXT_SIZE_255, text.flags & TEXT_SIZE_MASK);
	ASSERT_EQ(DISPLAY_PROFILE_3840_2160, text.flags & DISPLAY_PROFILE_MASK);
}

TEST_F(TextFixture, set_flag) {
	text.set_flags(TEXT_ALIGN_JUSTIFY |
			LINE_GAP_2_0 |
			TEXT_SIZE_255 |
			DISPLAY_PROFILE_3840_2160);

	ASSERT_EQ(TEXT_ALIGN_JUSTIFY, text.flags & TEXT_ALIGN_MASK);
	ASSERT_EQ(LINE_GAP_2_0, text.flags & LINE_GAP_MASK);
	ASSERT_EQ(TEXT_SIZE_255, text.flags & TEXT_SIZE_MASK);
	ASSERT_EQ(DISPLAY_PROFILE_3840_2160, text.flags & DISPLAY_PROFILE_MASK);

	text.set_flag(DISPLAY_PROFILE_1280_720, DISPLAY_PROFILE_MASK);
	ASSERT_EQ(DISPLAY_PROFILE_1280_720, text.flags & DISPLAY_PROFILE_MASK);
	ASSERT_EQ(TEXT_ALIGN_JUSTIFY, text.flags & TEXT_ALIGN_MASK);
	ASSERT_EQ(LINE_GAP_2_0, text.flags & LINE_GAP_MASK);
	ASSERT_EQ(TEXT_SIZE_255, text.flags & TEXT_SIZE_MASK);

	text.set_flag(TEXT_ALIGN_RIGHT, TEXT_ALIGN_MASK);
	ASSERT_EQ(DISPLAY_PROFILE_1280_720, text.flags & DISPLAY_PROFILE_MASK);
	ASSERT_EQ(TEXT_ALIGN_RIGHT, text.flags & TEXT_ALIGN_MASK);
	ASSERT_EQ(LINE_GAP_2_0, text.flags & LINE_GAP_MASK);
	ASSERT_EQ(TEXT_SIZE_255, text.flags & TEXT_SIZE_MASK);

	text.set_flag(LINE_GAP_1_5, LINE_GAP_MASK);
	ASSERT_EQ(DISPLAY_PROFILE_1280_720, text.flags & DISPLAY_PROFILE_MASK);
	ASSERT_EQ(TEXT_ALIGN_RIGHT, text.flags & TEXT_ALIGN_MASK);
	ASSERT_EQ(LINE_GAP_1_5, text.flags & LINE_GAP_MASK);
	ASSERT_EQ(TEXT_SIZE_255, text.flags & TEXT_SIZE_MASK);

	text.set_flag(TEXT_SIZE_225, TEXT_SIZE_MASK);
	ASSERT_EQ(DISPLAY_PROFILE_1280_720, text.flags & DISPLAY_PROFILE_MASK);
	ASSERT_EQ(TEXT_ALIGN_RIGHT, text.flags & TEXT_ALIGN_MASK);
	ASSERT_EQ(LINE_GAP_1_5, text.flags & LINE_GAP_MASK);
	ASSERT_EQ(TEXT_SIZE_225, text.flags & TEXT_SIZE_MASK);
}

TEST_F(TextFixture, aspect_ratios) {
	text.set_flags(DISPLAY_PROFILE_640_480);
	ASSERT_NEAR(4. / 3., text.get_aspect_ratio(), 0.0000001);

	text.set_flags(DISPLAY_PROFILE_1280_720);
	ASSERT_NEAR(16. / 9., text.get_aspect_ratio(), 0.0000001);

	text.set_flags(DISPLAY_PROFILE_1920_1080);
	ASSERT_NEAR(16. / 9., text.get_aspect_ratio(), 0.0000001);

	text.set_flags(DISPLAY_PROFILE_2560_1440);
	ASSERT_NEAR(16. / 9., text.get_aspect_ratio(), 0.0000001);

	text.set_flags(DISPLAY_PROFILE_2048_1080);
	ASSERT_NEAR(1. / 1.77, text.get_aspect_ratio(), 0.0000001);

	text.set_flags(DISPLAY_PROFILE_3840_2160);
	ASSERT_NEAR(1. / 1.9, text.get_aspect_ratio(), 0.0000001);

	text.set_flags(DISPLAY_PROFILE_7680_4320);
	ASSERT_NEAR(16. / 9., text.get_aspect_ratio(), 0.0000001);
}

TEST_F(TextFixture, line_gap) {
	text.set_flags(LINE_GAP_1_0);
	ASSERT_NEAR(1.0, text.get_line_gap(), 0.0001);

	text.set_flags(LINE_GAP_1_15);
	ASSERT_NEAR(1.15, text.get_line_gap(), 0.0001);

	text.set_flags(LINE_GAP_1_5);
	ASSERT_NEAR(1.5, text.get_line_gap(), 0.0001);

	text.set_flags(LINE_GAP_2_0);
	ASSERT_NEAR(2.0, text.get_line_gap(), 0.0001);
}

TEST_F(TextFixture, text_size) {
	text.set_flags(TEXT_SIZE_1);
	ASSERT_EQ(1, text.get_text_size());

	text.set_flags(TEXT_SIZE_2);
	ASSERT_EQ(2, text.get_text_size());

	text.set_flags(TEXT_SIZE_3);
	ASSERT_EQ(3, text.get_text_size());

	text.set_flags(TEXT_SIZE_4);
	ASSERT_EQ(4, text.get_text_size());

	text.set_flags(TEXT_SIZE_5);
	ASSERT_EQ(5, text.get_text_size());

	text.set_flags(TEXT_SIZE_6);
	ASSERT_EQ(6, text.get_text_size());

	text.set_flags(TEXT_SIZE_7);
	ASSERT_EQ(7, text.get_text_size());

	text.set_flags(TEXT_SIZE_8);
	ASSERT_EQ(8, text.get_text_size());

	text.set_flags(TEXT_SIZE_9);
	ASSERT_EQ(9, text.get_text_size());

	text.set_flags(TEXT_SIZE_10);
	ASSERT_EQ(10, text.get_text_size());

	text.set_flags(TEXT_SIZE_11);
	ASSERT_EQ(11, text.get_text_size());

	text.set_flags(TEXT_SIZE_12);
	ASSERT_EQ(12, text.get_text_size());

	text.set_flags(TEXT_SIZE_13);
	ASSERT_EQ(13, text.get_text_size());

	text.set_flags(TEXT_SIZE_14);
	ASSERT_EQ(14, text.get_text_size());

	text.set_flags(TEXT_SIZE_15);
	ASSERT_EQ(15, text.get_text_size());

	text.set_flags(TEXT_SIZE_16);
	ASSERT_EQ(16, text.get_text_size());

	text.set_flags(TEXT_SIZE_17);
	ASSERT_EQ(17, text.get_text_size());

	text.set_flags(TEXT_SIZE_18);
	ASSERT_EQ(18, text.get_text_size());

	text.set_flags(TEXT_SIZE_19);
	ASSERT_EQ(19, text.get_text_size());

	text.set_flags(TEXT_SIZE_20);
	ASSERT_EQ(20, text.get_text_size());

	text.set_flags(TEXT_SIZE_21);
	ASSERT_EQ(21, text.get_text_size());

	text.set_flags(TEXT_SIZE_22);
	ASSERT_EQ(22, text.get_text_size());

	text.set_flags(TEXT_SIZE_23);
	ASSERT_EQ(23, text.get_text_size());

	text.set_flags(TEXT_SIZE_24);
	ASSERT_EQ(24, text.get_text_size());

	text.set_flags(TEXT_SIZE_25);
	ASSERT_EQ(25, text.get_text_size());

	text.set_flags(TEXT_SIZE_26);
	ASSERT_EQ(26, text.get_text_size());

	text.set_flags(TEXT_SIZE_27);
	ASSERT_EQ(27, text.get_text_size());

	text.set_flags(TEXT_SIZE_28);
	ASSERT_EQ(28, text.get_text_size());

	text.set_flags(TEXT_SIZE_29);
	ASSERT_EQ(29, text.get_text_size());

	text.set_flags(TEXT_SIZE_30);
	ASSERT_EQ(30, text.get_text_size());

	text.set_flags(TEXT_SIZE_31);
	ASSERT_EQ(31, text.get_text_size());

	text.set_flags(TEXT_SIZE_32);
	ASSERT_EQ(32, text.get_text_size());

	text.set_flags(TEXT_SIZE_33);
	ASSERT_EQ(33, text.get_text_size());

	text.set_flags(TEXT_SIZE_34);
	ASSERT_EQ(34, text.get_text_size());

	text.set_flags(TEXT_SIZE_35);
	ASSERT_EQ(35, text.get_text_size());

	text.set_flags(TEXT_SIZE_36);
	ASSERT_EQ(36, text.get_text_size());

	text.set_flags(TEXT_SIZE_37);
	ASSERT_EQ(37, text.get_text_size());

	text.set_flags(TEXT_SIZE_38);
	ASSERT_EQ(38, text.get_text_size());

	text.set_flags(TEXT_SIZE_39);
	ASSERT_EQ(39, text.get_text_size());

	text.set_flags(TEXT_SIZE_40);
	ASSERT_EQ(40, text.get_text_size());

	text.set_flags(TEXT_SIZE_41);
	ASSERT_EQ(41, text.get_text_size());

	text.set_flags(TEXT_SIZE_42);
	ASSERT_EQ(42, text.get_text_size());

	text.set_flags(TEXT_SIZE_43);
	ASSERT_EQ(43, text.get_text_size());

	text.set_flags(TEXT_SIZE_44);
	ASSERT_EQ(44, text.get_text_size());

	text.set_flags(TEXT_SIZE_45);
	ASSERT_EQ(45, text.get_text_size());

	text.set_flags(TEXT_SIZE_46);
	ASSERT_EQ(46, text.get_text_size());

	text.set_flags(TEXT_SIZE_47);
	ASSERT_EQ(47, text.get_text_size());

	text.set_flags(TEXT_SIZE_48);
	ASSERT_EQ(48, text.get_text_size());

	text.set_flags(TEXT_SIZE_49);
	ASSERT_EQ(49, text.get_text_size());

	text.set_flags(TEXT_SIZE_50);
	ASSERT_EQ(50, text.get_text_size());

	text.set_flags(TEXT_SIZE_51);
	ASSERT_EQ(51, text.get_text_size());

	text.set_flags(TEXT_SIZE_52);
	ASSERT_EQ(52, text.get_text_size());

	text.set_flags(TEXT_SIZE_53);
	ASSERT_EQ(53, text.get_text_size());

	text.set_flags(TEXT_SIZE_54);
	ASSERT_EQ(54, text.get_text_size());

	text.set_flags(TEXT_SIZE_55);
	ASSERT_EQ(55, text.get_text_size());

	text.set_flags(TEXT_SIZE_56);
	ASSERT_EQ(56, text.get_text_size());

	text.set_flags(TEXT_SIZE_57);
	ASSERT_EQ(57, text.get_text_size());

	text.set_flags(TEXT_SIZE_58);
	ASSERT_EQ(58, text.get_text_size());

	text.set_flags(TEXT_SIZE_59);
	ASSERT_EQ(59, text.get_text_size());

	text.set_flags(TEXT_SIZE_60);
	ASSERT_EQ(60, text.get_text_size());

	text.set_flags(TEXT_SIZE_61);
	ASSERT_EQ(61, text.get_text_size());

	text.set_flags(TEXT_SIZE_62);
	ASSERT_EQ(62, text.get_text_size());

	text.set_flags(TEXT_SIZE_63);
	ASSERT_EQ(63, text.get_text_size());

	text.set_flags(TEXT_SIZE_64);
	ASSERT_EQ(64, text.get_text_size());

	text.set_flags(TEXT_SIZE_65);
	ASSERT_EQ(65, text.get_text_size());

	text.set_flags(TEXT_SIZE_66);
	ASSERT_EQ(66, text.get_text_size());

	text.set_flags(TEXT_SIZE_67);
	ASSERT_EQ(67, text.get_text_size());

	text.set_flags(TEXT_SIZE_68);
	ASSERT_EQ(68, text.get_text_size());

	text.set_flags(TEXT_SIZE_69);
	ASSERT_EQ(69, text.get_text_size());

	text.set_flags(TEXT_SIZE_70);
	ASSERT_EQ(70, text.get_text_size());

	text.set_flags(TEXT_SIZE_71);
	ASSERT_EQ(71, text.get_text_size());

	text.set_flags(TEXT_SIZE_72);
	ASSERT_EQ(72, text.get_text_size());

	text.set_flags(TEXT_SIZE_73);
	ASSERT_EQ(73, text.get_text_size());

	text.set_flags(TEXT_SIZE_74);
	ASSERT_EQ(74, text.get_text_size());

	text.set_flags(TEXT_SIZE_75);
	ASSERT_EQ(75, text.get_text_size());

	text.set_flags(TEXT_SIZE_76);
	ASSERT_EQ(76, text.get_text_size());

	text.set_flags(TEXT_SIZE_77);
	ASSERT_EQ(77, text.get_text_size());

	text.set_flags(TEXT_SIZE_78);
	ASSERT_EQ(78, text.get_text_size());

	text.set_flags(TEXT_SIZE_79);
	ASSERT_EQ(79, text.get_text_size());

	text.set_flags(TEXT_SIZE_80);
	ASSERT_EQ(80, text.get_text_size());

	text.set_flags(TEXT_SIZE_81);
	ASSERT_EQ(81, text.get_text_size());

	text.set_flags(TEXT_SIZE_82);
	ASSERT_EQ(82, text.get_text_size());

	text.set_flags(TEXT_SIZE_83);
	ASSERT_EQ(83, text.get_text_size());

	text.set_flags(TEXT_SIZE_84);
	ASSERT_EQ(84, text.get_text_size());

	text.set_flags(TEXT_SIZE_85);
	ASSERT_EQ(85, text.get_text_size());

	text.set_flags(TEXT_SIZE_86);
	ASSERT_EQ(86, text.get_text_size());

	text.set_flags(TEXT_SIZE_87);
	ASSERT_EQ(87, text.get_text_size());

	text.set_flags(TEXT_SIZE_88);
	ASSERT_EQ(88, text.get_text_size());

	text.set_flags(TEXT_SIZE_89);
	ASSERT_EQ(89, text.get_text_size());

	text.set_flags(TEXT_SIZE_90);
	ASSERT_EQ(90, text.get_text_size());

	text.set_flags(TEXT_SIZE_91);
	ASSERT_EQ(91, text.get_text_size());

	text.set_flags(TEXT_SIZE_92);
	ASSERT_EQ(92, text.get_text_size());

	text.set_flags(TEXT_SIZE_93);
	ASSERT_EQ(93, text.get_text_size());

	text.set_flags(TEXT_SIZE_94);
	ASSERT_EQ(94, text.get_text_size());

	text.set_flags(TEXT_SIZE_95);
	ASSERT_EQ(95, text.get_text_size());

	text.set_flags(TEXT_SIZE_96);
	ASSERT_EQ(96, text.get_text_size());

	text.set_flags(TEXT_SIZE_97);
	ASSERT_EQ(97, text.get_text_size());

	text.set_flags(TEXT_SIZE_98);
	ASSERT_EQ(98, text.get_text_size());

	text.set_flags(TEXT_SIZE_99);
	ASSERT_EQ(99, text.get_text_size());

	text.set_flags(TEXT_SIZE_100);
	ASSERT_EQ(100, text.get_text_size());

	text.set_flags(TEXT_SIZE_101);
	ASSERT_EQ(101, text.get_text_size());

	text.set_flags(TEXT_SIZE_102);
	ASSERT_EQ(102, text.get_text_size());

	text.set_flags(TEXT_SIZE_103);
	ASSERT_EQ(103, text.get_text_size());

	text.set_flags(TEXT_SIZE_104);
	ASSERT_EQ(104, text.get_text_size());

	text.set_flags(TEXT_SIZE_105);
	ASSERT_EQ(105, text.get_text_size());

	text.set_flags(TEXT_SIZE_106);
	ASSERT_EQ(106, text.get_text_size());

	text.set_flags(TEXT_SIZE_107);
	ASSERT_EQ(107, text.get_text_size());

	text.set_flags(TEXT_SIZE_108);
	ASSERT_EQ(108, text.get_text_size());

	text.set_flags(TEXT_SIZE_109);
	ASSERT_EQ(109, text.get_text_size());

	text.set_flags(TEXT_SIZE_110);
	ASSERT_EQ(110, text.get_text_size());

	text.set_flags(TEXT_SIZE_111);
	ASSERT_EQ(111, text.get_text_size());

	text.set_flags(TEXT_SIZE_112);
	ASSERT_EQ(112, text.get_text_size());

	text.set_flags(TEXT_SIZE_113);
	ASSERT_EQ(113, text.get_text_size());

	text.set_flags(TEXT_SIZE_114);
	ASSERT_EQ(114, text.get_text_size());

	text.set_flags(TEXT_SIZE_115);
	ASSERT_EQ(115, text.get_text_size());

	text.set_flags(TEXT_SIZE_116);
	ASSERT_EQ(116, text.get_text_size());

	text.set_flags(TEXT_SIZE_117);
	ASSERT_EQ(117, text.get_text_size());

	text.set_flags(TEXT_SIZE_118);
	ASSERT_EQ(118, text.get_text_size());

	text.set_flags(TEXT_SIZE_119);
	ASSERT_EQ(119, text.get_text_size());

	text.set_flags(TEXT_SIZE_120);
	ASSERT_EQ(120, text.get_text_size());

	text.set_flags(TEXT_SIZE_121);
	ASSERT_EQ(121, text.get_text_size());

	text.set_flags(TEXT_SIZE_122);
	ASSERT_EQ(122, text.get_text_size());

	text.set_flags(TEXT_SIZE_123);
	ASSERT_EQ(123, text.get_text_size());

	text.set_flags(TEXT_SIZE_124);
	ASSERT_EQ(124, text.get_text_size());

	text.set_flags(TEXT_SIZE_125);
	ASSERT_EQ(125, text.get_text_size());

	text.set_flags(TEXT_SIZE_126);
	ASSERT_EQ(126, text.get_text_size());

	text.set_flags(TEXT_SIZE_127);
	ASSERT_EQ(127, text.get_text_size());

	text.set_flags(TEXT_SIZE_128);
	ASSERT_EQ(128, text.get_text_size());

	text.set_flags(TEXT_SIZE_129);
	ASSERT_EQ(129, text.get_text_size());

	text.set_flags(TEXT_SIZE_130);
	ASSERT_EQ(130, text.get_text_size());

	text.set_flags(TEXT_SIZE_131);
	ASSERT_EQ(131, text.get_text_size());

	text.set_flags(TEXT_SIZE_132);
	ASSERT_EQ(132, text.get_text_size());

	text.set_flags(TEXT_SIZE_133);
	ASSERT_EQ(133, text.get_text_size());

	text.set_flags(TEXT_SIZE_134);
	ASSERT_EQ(134, text.get_text_size());

	text.set_flags(TEXT_SIZE_135);
	ASSERT_EQ(135, text.get_text_size());

	text.set_flags(TEXT_SIZE_136);
	ASSERT_EQ(136, text.get_text_size());

	text.set_flags(TEXT_SIZE_137);
	ASSERT_EQ(137, text.get_text_size());

	text.set_flags(TEXT_SIZE_138);
	ASSERT_EQ(138, text.get_text_size());

	text.set_flags(TEXT_SIZE_139);
	ASSERT_EQ(139, text.get_text_size());

	text.set_flags(TEXT_SIZE_140);
	ASSERT_EQ(140, text.get_text_size());

	text.set_flags(TEXT_SIZE_141);
	ASSERT_EQ(141, text.get_text_size());

	text.set_flags(TEXT_SIZE_142);
	ASSERT_EQ(142, text.get_text_size());

	text.set_flags(TEXT_SIZE_143);
	ASSERT_EQ(143, text.get_text_size());

	text.set_flags(TEXT_SIZE_144);
	ASSERT_EQ(144, text.get_text_size());

	text.set_flags(TEXT_SIZE_145);
	ASSERT_EQ(145, text.get_text_size());

	text.set_flags(TEXT_SIZE_146);
	ASSERT_EQ(146, text.get_text_size());

	text.set_flags(TEXT_SIZE_147);
	ASSERT_EQ(147, text.get_text_size());

	text.set_flags(TEXT_SIZE_148);
	ASSERT_EQ(148, text.get_text_size());

	text.set_flags(TEXT_SIZE_149);
	ASSERT_EQ(149, text.get_text_size());

	text.set_flags(TEXT_SIZE_150);
	ASSERT_EQ(150, text.get_text_size());

	text.set_flags(TEXT_SIZE_151);
	ASSERT_EQ(151, text.get_text_size());

	text.set_flags(TEXT_SIZE_152);
	ASSERT_EQ(152, text.get_text_size());

	text.set_flags(TEXT_SIZE_153);
	ASSERT_EQ(153, text.get_text_size());

	text.set_flags(TEXT_SIZE_154);
	ASSERT_EQ(154, text.get_text_size());

	text.set_flags(TEXT_SIZE_155);
	ASSERT_EQ(155, text.get_text_size());

	text.set_flags(TEXT_SIZE_156);
	ASSERT_EQ(156, text.get_text_size());

	text.set_flags(TEXT_SIZE_157);
	ASSERT_EQ(157, text.get_text_size());

	text.set_flags(TEXT_SIZE_158);
	ASSERT_EQ(158, text.get_text_size());

	text.set_flags(TEXT_SIZE_159);
	ASSERT_EQ(159, text.get_text_size());

	text.set_flags(TEXT_SIZE_160);
	ASSERT_EQ(160, text.get_text_size());

	text.set_flags(TEXT_SIZE_161);
	ASSERT_EQ(161, text.get_text_size());

	text.set_flags(TEXT_SIZE_162);
	ASSERT_EQ(162, text.get_text_size());

	text.set_flags(TEXT_SIZE_163);
	ASSERT_EQ(163, text.get_text_size());

	text.set_flags(TEXT_SIZE_164);
	ASSERT_EQ(164, text.get_text_size());

	text.set_flags(TEXT_SIZE_165);
	ASSERT_EQ(165, text.get_text_size());

	text.set_flags(TEXT_SIZE_166);
	ASSERT_EQ(166, text.get_text_size());

	text.set_flags(TEXT_SIZE_167);
	ASSERT_EQ(167, text.get_text_size());

	text.set_flags(TEXT_SIZE_168);
	ASSERT_EQ(168, text.get_text_size());

	text.set_flags(TEXT_SIZE_169);
	ASSERT_EQ(169, text.get_text_size());

	text.set_flags(TEXT_SIZE_170);
	ASSERT_EQ(170, text.get_text_size());

	text.set_flags(TEXT_SIZE_171);
	ASSERT_EQ(171, text.get_text_size());

	text.set_flags(TEXT_SIZE_172);
	ASSERT_EQ(172, text.get_text_size());

	text.set_flags(TEXT_SIZE_173);
	ASSERT_EQ(173, text.get_text_size());

	text.set_flags(TEXT_SIZE_174);
	ASSERT_EQ(174, text.get_text_size());

	text.set_flags(TEXT_SIZE_175);
	ASSERT_EQ(175, text.get_text_size());

	text.set_flags(TEXT_SIZE_176);
	ASSERT_EQ(176, text.get_text_size());

	text.set_flags(TEXT_SIZE_177);
	ASSERT_EQ(177, text.get_text_size());

	text.set_flags(TEXT_SIZE_178);
	ASSERT_EQ(178, text.get_text_size());

	text.set_flags(TEXT_SIZE_179);
	ASSERT_EQ(179, text.get_text_size());

	text.set_flags(TEXT_SIZE_180);
	ASSERT_EQ(180, text.get_text_size());

	text.set_flags(TEXT_SIZE_181);
	ASSERT_EQ(181, text.get_text_size());

	text.set_flags(TEXT_SIZE_182);
	ASSERT_EQ(182, text.get_text_size());

	text.set_flags(TEXT_SIZE_183);
	ASSERT_EQ(183, text.get_text_size());

	text.set_flags(TEXT_SIZE_184);
	ASSERT_EQ(184, text.get_text_size());

	text.set_flags(TEXT_SIZE_185);
	ASSERT_EQ(185, text.get_text_size());

	text.set_flags(TEXT_SIZE_186);
	ASSERT_EQ(186, text.get_text_size());

	text.set_flags(TEXT_SIZE_187);
	ASSERT_EQ(187, text.get_text_size());

	text.set_flags(TEXT_SIZE_188);
	ASSERT_EQ(188, text.get_text_size());

	text.set_flags(TEXT_SIZE_189);
	ASSERT_EQ(189, text.get_text_size());

	text.set_flags(TEXT_SIZE_190);
	ASSERT_EQ(190, text.get_text_size());

	text.set_flags(TEXT_SIZE_191);
	ASSERT_EQ(191, text.get_text_size());

	text.set_flags(TEXT_SIZE_192);
	ASSERT_EQ(192, text.get_text_size());

	text.set_flags(TEXT_SIZE_193);
	ASSERT_EQ(193, text.get_text_size());

	text.set_flags(TEXT_SIZE_194);
	ASSERT_EQ(194, text.get_text_size());

	text.set_flags(TEXT_SIZE_195);
	ASSERT_EQ(195, text.get_text_size());

	text.set_flags(TEXT_SIZE_196);
	ASSERT_EQ(196, text.get_text_size());

	text.set_flags(TEXT_SIZE_197);
	ASSERT_EQ(197, text.get_text_size());

	text.set_flags(TEXT_SIZE_198);
	ASSERT_EQ(198, text.get_text_size());

	text.set_flags(TEXT_SIZE_199);
	ASSERT_EQ(199, text.get_text_size());

	text.set_flags(TEXT_SIZE_200);
	ASSERT_EQ(200, text.get_text_size());

	text.set_flags(TEXT_SIZE_201);
	ASSERT_EQ(201, text.get_text_size());

	text.set_flags(TEXT_SIZE_202);
	ASSERT_EQ(202, text.get_text_size());

	text.set_flags(TEXT_SIZE_203);
	ASSERT_EQ(203, text.get_text_size());

	text.set_flags(TEXT_SIZE_204);
	ASSERT_EQ(204, text.get_text_size());

	text.set_flags(TEXT_SIZE_205);
	ASSERT_EQ(205, text.get_text_size());

	text.set_flags(TEXT_SIZE_206);
	ASSERT_EQ(206, text.get_text_size());

	text.set_flags(TEXT_SIZE_207);
	ASSERT_EQ(207, text.get_text_size());

	text.set_flags(TEXT_SIZE_208);
	ASSERT_EQ(208, text.get_text_size());

	text.set_flags(TEXT_SIZE_209);
	ASSERT_EQ(209, text.get_text_size());

	text.set_flags(TEXT_SIZE_210);
	ASSERT_EQ(210, text.get_text_size());

	text.set_flags(TEXT_SIZE_211);
	ASSERT_EQ(211, text.get_text_size());

	text.set_flags(TEXT_SIZE_212);
	ASSERT_EQ(212, text.get_text_size());

	text.set_flags(TEXT_SIZE_213);
	ASSERT_EQ(213, text.get_text_size());

	text.set_flags(TEXT_SIZE_214);
	ASSERT_EQ(214, text.get_text_size());

	text.set_flags(TEXT_SIZE_215);
	ASSERT_EQ(215, text.get_text_size());

	text.set_flags(TEXT_SIZE_216);
	ASSERT_EQ(216, text.get_text_size());

	text.set_flags(TEXT_SIZE_217);
	ASSERT_EQ(217, text.get_text_size());

	text.set_flags(TEXT_SIZE_218);
	ASSERT_EQ(218, text.get_text_size());

	text.set_flags(TEXT_SIZE_219);
	ASSERT_EQ(219, text.get_text_size());

	text.set_flags(TEXT_SIZE_220);
	ASSERT_EQ(220, text.get_text_size());

	text.set_flags(TEXT_SIZE_221);
	ASSERT_EQ(221, text.get_text_size());

	text.set_flags(TEXT_SIZE_222);
	ASSERT_EQ(222, text.get_text_size());

	text.set_flags(TEXT_SIZE_223);
	ASSERT_EQ(223, text.get_text_size());

	text.set_flags(TEXT_SIZE_224);
	ASSERT_EQ(224, text.get_text_size());

	text.set_flags(TEXT_SIZE_225);
	ASSERT_EQ(225, text.get_text_size());

	text.set_flags(TEXT_SIZE_226);
	ASSERT_EQ(226, text.get_text_size());

	text.set_flags(TEXT_SIZE_227);
	ASSERT_EQ(227, text.get_text_size());

	text.set_flags(TEXT_SIZE_228);
	ASSERT_EQ(228, text.get_text_size());

	text.set_flags(TEXT_SIZE_229);
	ASSERT_EQ(229, text.get_text_size());

	text.set_flags(TEXT_SIZE_230);
	ASSERT_EQ(230, text.get_text_size());

	text.set_flags(TEXT_SIZE_231);
	ASSERT_EQ(231, text.get_text_size());

	text.set_flags(TEXT_SIZE_232);
	ASSERT_EQ(232, text.get_text_size());

	text.set_flags(TEXT_SIZE_233);
	ASSERT_EQ(233, text.get_text_size());

	text.set_flags(TEXT_SIZE_234);
	ASSERT_EQ(234, text.get_text_size());

	text.set_flags(TEXT_SIZE_235);
	ASSERT_EQ(235, text.get_text_size());

	text.set_flags(TEXT_SIZE_236);
	ASSERT_EQ(236, text.get_text_size());

	text.set_flags(TEXT_SIZE_237);
	ASSERT_EQ(237, text.get_text_size());

	text.set_flags(TEXT_SIZE_238);
	ASSERT_EQ(238, text.get_text_size());

	text.set_flags(TEXT_SIZE_239);
	ASSERT_EQ(239, text.get_text_size());

	text.set_flags(TEXT_SIZE_240);
	ASSERT_EQ(240, text.get_text_size());

	text.set_flags(TEXT_SIZE_241);
	ASSERT_EQ(241, text.get_text_size());

	text.set_flags(TEXT_SIZE_242);
	ASSERT_EQ(242, text.get_text_size());

	text.set_flags(TEXT_SIZE_243);
	ASSERT_EQ(243, text.get_text_size());

	text.set_flags(TEXT_SIZE_244);
	ASSERT_EQ(244, text.get_text_size());

	text.set_flags(TEXT_SIZE_245);
	ASSERT_EQ(245, text.get_text_size());

	text.set_flags(TEXT_SIZE_246);
	ASSERT_EQ(246, text.get_text_size());

	text.set_flags(TEXT_SIZE_247);
	ASSERT_EQ(247, text.get_text_size());

	text.set_flags(TEXT_SIZE_248);
	ASSERT_EQ(248, text.get_text_size());

	text.set_flags(TEXT_SIZE_249);
	ASSERT_EQ(249, text.get_text_size());

	text.set_flags(TEXT_SIZE_250);
	ASSERT_EQ(250, text.get_text_size());

	text.set_flags(TEXT_SIZE_251);
	ASSERT_EQ(251, text.get_text_size());

	text.set_flags(TEXT_SIZE_252);
	ASSERT_EQ(252, text.get_text_size());

	text.set_flags(TEXT_SIZE_253);
	ASSERT_EQ(253, text.get_text_size());

	text.set_flags(TEXT_SIZE_254);
	ASSERT_EQ(254, text.get_text_size());

	text.set_flags(TEXT_SIZE_255);
	ASSERT_EQ(255, text.get_text_size());
}

TEST_F(TextFixture, display_width) {
	text.set_flags(DISPLAY_PROFILE_640_480);
	ASSERT_EQ(640, text.get_display_width());

	text.set_flags(DISPLAY_PROFILE_1280_720);
	ASSERT_EQ(1280, text.get_display_width());

	text.set_flags(DISPLAY_PROFILE_1920_1080);
	ASSERT_EQ(1920, text.get_display_width());

	text.set_flags(DISPLAY_PROFILE_2560_1440);
	ASSERT_EQ(2560, text.get_display_width());

	text.set_flags(DISPLAY_PROFILE_2048_1080);
	ASSERT_EQ(2048, text.get_display_width());

	text.set_flags(DISPLAY_PROFILE_3840_2160);
	ASSERT_EQ(3840, text.get_display_width());

	text.set_flags(DISPLAY_PROFILE_7680_4320);
	ASSERT_EQ(7680, text.get_display_width());
}

TEST_F(TextFixture, display_height) {
	text.set_flags(DISPLAY_PROFILE_640_480);
	ASSERT_EQ(480, text.get_display_height());

	text.set_flags(DISPLAY_PROFILE_1280_720);
	ASSERT_EQ(720, text.get_display_height());

	text.set_flags(DISPLAY_PROFILE_1920_1080);
	ASSERT_EQ(1080, text.get_display_height());

	text.set_flags(DISPLAY_PROFILE_2560_1440);
	ASSERT_EQ(1440, text.get_display_height());

	text.set_flags(DISPLAY_PROFILE_2048_1080);
	ASSERT_EQ(1080, text.get_display_height());

	text.set_flags(DISPLAY_PROFILE_3840_2160);
	ASSERT_EQ(2160, text.get_display_height());

	text.set_flags(DISPLAY_PROFILE_7680_4320);
	ASSERT_EQ(4320, text.get_display_height());
}
