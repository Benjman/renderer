#ifndef CORE_COLORS_H
#define CORE_COLORS_H

#include <glm/vec3.hpp>

static constexpr glm::vec3 Red50 = glm::vec3(1.0, 0.921569, 0.933333);                         // #ffecee
static constexpr glm::vec3 Red100 = glm::vec3(1.0, 0.803922, 0.823529);                        // #ffced2
static constexpr glm::vec3 Red200 = glm::vec3(0.937255, 0.603922, 0.603922);                   // #f09b9b
static constexpr glm::vec3 Red300 = glm::vec3(0.898039, 0.45098, 0.45098);                     // #e57373
static constexpr glm::vec3 Red400 = glm::vec3(0.937255, 0.32549, 0.313725);                    // #f05350
static constexpr glm::vec3 Red500 = glm::vec3(0.956863, 0.262745, 0.211765);                   // #f54337
static constexpr glm::vec3 Red600 = glm::vec3(0.898039, 0.223529, 0.207843);                   // #e53935
static constexpr glm::vec3 Red700 = glm::vec3(0.827451, 0.184314, 0.184314);                   // #d43030
static constexpr glm::vec3 Red800 = glm::vec3(0.776471, 0.156863, 0.156863);                   // #c72929
static constexpr glm::vec3 Red900 = glm::vec3(0.717647, 0.109804, 0.109804);                   // #b71d1d
static constexpr glm::vec3 RedA100 = glm::vec3(1.0, 0.541176, 0.501961);                       // #ff8a81
static constexpr glm::vec3 RedA200 = glm::vec3(1.0, 0.321569, 0.321569);                       // #ff5353
static constexpr glm::vec3 RedA400 = glm::vec3(1.0, 0.090196, 0.266667);                       // #ff1745
static constexpr glm::vec3 RedA700 = glm::vec3(0.835294, 0.0, 0.0);                            // #d50000
                                                                                           
static constexpr glm::vec3 Pink50 = glm::vec3(0.988235, 0.894118, 0.92549);                    // #fce5ec
static constexpr glm::vec3 Pink100 = glm::vec3(0.972549, 0.733333, 0.815686);                  // #f8bbd0
static constexpr glm::vec3 Pink200 = glm::vec3(0.956863, 0.560784, 0.694118);                  // #f58fb2
static constexpr glm::vec3 Pink300 = glm::vec3(0.941176, 0.384314, 0.572549);                  // #f06392
static constexpr glm::vec3 Pink400 = glm::vec3(0.92549, 0.25098, 0.478431);                    // #ec407a
static constexpr glm::vec3 Pink500 = glm::vec3(0.913725, 0.117647, 0.388235);                  // #e91e63
static constexpr glm::vec3 Pink600 = glm::vec3(0.847059, 0.105882, 0.376471);                  // #d91b61
static constexpr glm::vec3 Pink700 = glm::vec3(0.760784, 0.094118, 0.356863);                  // #c2195c
static constexpr glm::vec3 Pink800 = glm::vec3(0.678431, 0.078431, 0.341176);                  // #ad1457
static constexpr glm::vec3 Pink900 = glm::vec3(0.533333, 0.054902, 0.309804);                  // #880f50
static constexpr glm::vec3 PinkA100 = glm::vec3(1.0, 0.501961, 0.670588);                      // #ff81ab
static constexpr glm::vec3 PinkA200 = glm::vec3(1.0, 0.25098, 0.505882);                       // #ff4081
static constexpr glm::vec3 PinkA400 = glm::vec3(0.960784, 0.0, 0.341176);                      // #f50057
static constexpr glm::vec3 PinkA700 = glm::vec3(0.772549, 0.066667, 0.384314);                 // #c51263
                                                                                           
static constexpr glm::vec3 Purple50 = glm::vec3(0.952941, 0.898039, 0.960784);                 // #f3e5f5
static constexpr glm::vec3 Purple100 = glm::vec3(0.882353, 0.745098, 0.905882);                // #e2bee7
static constexpr glm::vec3 Purple200 = glm::vec3(0.807843, 0.576471, 0.847059);                // #ce94d9
static constexpr glm::vec3 Purple300 = glm::vec3(0.729412, 0.407843, 0.784314);                // #bb68c9
static constexpr glm::vec3 Purple400 = glm::vec3(0.670588, 0.278431, 0.737255);                // #ab47bd
static constexpr glm::vec3 Purple500 = glm::vec3(0.611765, 0.152941, 0.690196);                // #9d27b0
static constexpr glm::vec3 Purple600 = glm::vec3(0.556863, 0.141176, 0.666667);                // #8f24ab
static constexpr glm::vec3 Purple700 = glm::vec3(0.482353, 0.121569, 0.635294);                // #7c20a2
static constexpr glm::vec3 Purple800 = glm::vec3(0.415686, 0.105882, 0.603922);                // #6a1b9b
static constexpr glm::vec3 Purple900 = glm::vec3(0.290196, 0.078431, 0.54902);                 // #4a148d
static constexpr glm::vec3 PurpleA100 = glm::vec3(0.917647, 0.501961, 0.988235);               // #ea81fc
static constexpr glm::vec3 PurpleA200 = glm::vec3(0.878431, 0.25098, 0.984314);                // #e040fc
static constexpr glm::vec3 PurpleA400 = glm::vec3(0.835294, 0.0, 0.976471);                    // #d500fa
static constexpr glm::vec3 PurpleA700 = glm::vec3(0.666667, 0.0, 1.0);                         // #ab00ff
                                                                                           
static constexpr glm::vec3 DeepPurple50 = glm::vec3(0.929412, 0.905882, 0.964706);             // #eee7f7
static constexpr glm::vec3 DeepPurple100 = glm::vec3(0.819608, 0.768627, 0.913725);            // #d2c4e9
static constexpr glm::vec3 DeepPurple200 = glm::vec3(0.701961, 0.615686, 0.858824);            // #b49ddc
static constexpr glm::vec3 DeepPurple300 = glm::vec3(0.584314, 0.458824, 0.803922);            // #9676ce
static constexpr glm::vec3 DeepPurple400 = glm::vec3(0.494118, 0.341176, 0.760784);            // #7f57c2
static constexpr glm::vec3 DeepPurple500 = glm::vec3(0.403922, 0.227451, 0.717647);            // #683bb7
static constexpr glm::vec3 DeepPurple600 = glm::vec3(0.368627, 0.207843, 0.694118);            // #5e35b2
static constexpr glm::vec3 DeepPurple700 = glm::vec3(0.317647, 0.176471, 0.658824);            // #512ea9
static constexpr glm::vec3 DeepPurple800 = glm::vec3(0.270588, 0.152941, 0.627451);            // #4527a1
static constexpr glm::vec3 DeepPurple900 = glm::vec3(0.192157, 0.105882, 0.572549);            // #321b92
static constexpr glm::vec3 DeepPurpleA100 = glm::vec3(0.701961, 0.533333, 1.0);                // #b488ff
static constexpr glm::vec3 DeepPurpleA200 = glm::vec3(0.486275, 0.301961, 1.0);                // #7d4eff
static constexpr glm::vec3 DeepPurpleA400 = glm::vec3(0.396078, 0.121569, 1.0);                // #6520ff
static constexpr glm::vec3 DeepPurpleA700 = glm::vec3(0.384314, 0.0, 0.917647);                // #6300ea
                                                                                           
                                                                                           
static constexpr glm::vec3 Indigo50 = glm::vec3(0.909804, 0.917647, 0.964706);                 // #e9eaf7
static constexpr glm::vec3 Indigo100 = glm::vec3(0.772549, 0.792157, 0.913725);                // #c5cbe9
static constexpr glm::vec3 Indigo200 = glm::vec3(0.623529, 0.658824, 0.854902);                // #9fa9db
static constexpr glm::vec3 Indigo300 = glm::vec3(0.47451, 0.52549, 0.796078);                  // #7a86cb
static constexpr glm::vec3 Indigo400 = glm::vec3(0.360784, 0.419608, 0.752941);                // #5c6cc0
static constexpr glm::vec3 Indigo500 = glm::vec3(0.247059, 0.317647, 0.709804);                // #4051b6
static constexpr glm::vec3 Indigo600 = glm::vec3(0.223529, 0.286275, 0.670588);                // #394aab
static constexpr glm::vec3 Indigo700 = glm::vec3(0.188235, 0.247059, 0.623529);                // #30409f
static constexpr glm::vec3 Indigo800 = glm::vec3(0.156863, 0.207843, 0.576471);                // #293594
static constexpr glm::vec3 Indigo900 = glm::vec3(0.101961, 0.137255, 0.494118);                // #1b247f
static constexpr glm::vec3 IndigoA100 = glm::vec3(0.54902, 0.619608, 1.0);                     // #8d9fff
static constexpr glm::vec3 IndigoA200 = glm::vec3(0.32549, 0.427451, 0.996078);                // #536efe
static constexpr glm::vec3 IndigoA400 = glm::vec3(0.239216, 0.352941, 0.996078);               // #3e5afe
static constexpr glm::vec3 IndigoA700 = glm::vec3(0.188235, 0.309804, 0.996078);               // #3050fe
                                                                                           
                                                                                           
static constexpr glm::vec3 Blue50 = glm::vec3(0.890196, 0.94902, 0.992157);                    // #e3f3fe
static constexpr glm::vec3 Blue100 = glm::vec3(0.733333, 0.870588, 0.984314);                  // #bbdefc
static constexpr glm::vec3 Blue200 = glm::vec3(0.564706, 0.792157, 0.976471);                  // #91cbfa
static constexpr glm::vec3 Blue300 = glm::vec3(0.392157, 0.709804, 0.964706);                  // #65b6f7
static constexpr glm::vec3 Blue400 = glm::vec3(0.258824, 0.647059, 0.960784);                  // #43a6f5
static constexpr glm::vec3 Blue500 = glm::vec3(0.129412, 0.588235, 0.952941);                  // #2296f3
static constexpr glm::vec3 Blue600 = glm::vec3(0.117647, 0.533333, 0.898039);                  // #1e88e5
static constexpr glm::vec3 Blue700 = glm::vec3(0.098039, 0.462745, 0.823529);                  // #1976d2
static constexpr glm::vec3 Blue800 = glm::vec3(0.082353, 0.396078, 0.752941);                  // #1665c0
static constexpr glm::vec3 Blue900 = glm::vec3(0.05098, 0.278431, 0.631373);                   // #0d47a2
static constexpr glm::vec3 BlueA100 = glm::vec3(0.509804, 0.694118, 1.0);                      // #83b2ff
static constexpr glm::vec3 BlueA200 = glm::vec3(0.266667, 0.541176, 1.0);                      // #458aff
static constexpr glm::vec3 BlueA400 = glm::vec3(0.160784, 0.47451, 1.0);                       // #297aff
static constexpr glm::vec3 BlueA700 = glm::vec3(0.160784, 0.384314, 1.0);                      // #2963ff
                                                                                           
                                                                                           
static constexpr glm::vec3 LightBlue50 = glm::vec3(0.882353, 0.960784, 0.996078);              // #e2f5fe
static constexpr glm::vec3 LightBlue100 = glm::vec3(0.701961, 0.898039, 0.988235);             // #b4e5fc
static constexpr glm::vec3 LightBlue200 = glm::vec3(0.505882, 0.831373, 0.980392);             // #81d5fa
static constexpr glm::vec3 LightBlue300 = glm::vec3(0.309804, 0.764706, 0.968627);             // #50c4f7
static constexpr glm::vec3 LightBlue400 = glm::vec3(0.160784, 0.713725, 0.964706);             // #29b6f7
static constexpr glm::vec3 LightBlue500 = glm::vec3(0.011765, 0.662745, 0.956863);             // #04a9f5
static constexpr glm::vec3 LightBlue600 = glm::vec3(0.011765, 0.607843, 0.898039);             // #049be5
static constexpr glm::vec3 LightBlue700 = glm::vec3(0.007843, 0.533333, 0.819608);             // #0288d2
static constexpr glm::vec3 LightBlue800 = glm::vec3(0.007843, 0.466667, 0.741176);             // #0278bd
static constexpr glm::vec3 LightBlue900 = glm::vec3(0.003922, 0.341176, 0.607843);             // #02579b
static constexpr glm::vec3 LightBlueA100 = glm::vec3(0.501961, 0.847059, 1.0);                 // #81d9ff
static constexpr glm::vec3 LightBlueA200 = glm::vec3(0.25098, 0.768627, 1.0);                  // #40c4ff
static constexpr glm::vec3 LightBlueA400 = glm::vec3(0.0, 0.690196, 1.0);                      // #00b0ff
static constexpr glm::vec3 LightBlueA700 = glm::vec3(0.0, 0.568627, 0.917647);                 // #0091ea
                                                                                           
                                                                                           
static constexpr glm::vec3 Cyan50 = glm::vec3(0.878431, 0.968627, 0.980392);                   // #e0f7fa
static constexpr glm::vec3 Cyan100 = glm::vec3(0.698039, 0.921569, 0.94902);                   // #b2ecf3
static constexpr glm::vec3 Cyan200 = glm::vec3(0.501961, 0.870588, 0.917647);                  // #81deea
static constexpr glm::vec3 Cyan300 = glm::vec3(0.301961, 0.815686, 0.882353);                  // #4ed0e2
static constexpr glm::vec3 Cyan400 = glm::vec3(0.14902, 0.776471, 0.854902);                   // #27c7db
static constexpr glm::vec3 Cyan500 = glm::vec3(0.0, 0.737255, 0.831373);                       // #00bdd5
static constexpr glm::vec3 Cyan600 = glm::vec3(0.0, 0.67451, 0.756863);                        // #00adc2
static constexpr glm::vec3 Cyan700 = glm::vec3(0.0, 0.592157, 0.654902);                       // #0098a8
static constexpr glm::vec3 Cyan800 = glm::vec3(0.0, 0.513725, 0.560784);                       // #00838f
static constexpr glm::vec3 Cyan900 = glm::vec3(0.0, 0.376471, 0.392157);                       // #006165
static constexpr glm::vec3 CyanA100 = glm::vec3(0.517647, 1.0, 1.0);                           // #84ffff
static constexpr glm::vec3 CyanA200 = glm::vec3(0.094118, 1.0, 1.0);                           // #19ffff
static constexpr glm::vec3 CyanA400 = glm::vec3(0.0, 0.898039, 1.0);                           // #00e5ff
static constexpr glm::vec3 CyanA700 = glm::vec3(0.0, 0.721569, 0.831373);                      // #00b9d5
                                                                                           
                                                                                           
static constexpr glm::vec3 Teal50 = glm::vec3(0.878431, 0.94902, 0.945098);                    // #e0f3f1
static constexpr glm::vec3 Teal100 = glm::vec3(0.698039, 0.87451, 0.858824);                   // #b2e0dc
static constexpr glm::vec3 Teal200 = glm::vec3(0.501961, 0.796078, 0.768627);                  // #81cbc4
static constexpr glm::vec3 Teal300 = glm::vec3(0.301961, 0.713725, 0.67451);                   // #4eb6ad
static constexpr glm::vec3 Teal400 = glm::vec3(0.14902, 0.65098, 0.603922);                    // #27a69b
static constexpr glm::vec3 Teal500 = glm::vec3(0.0, 0.588235, 0.533333);                       // #009688
static constexpr glm::vec3 Teal600 = glm::vec3(0.0, 0.537255, 0.482353);                       // #008a7c
static constexpr glm::vec3 Teal700 = glm::vec3(0.0, 0.47451, 0.419608);                        // #007a6c
static constexpr glm::vec3 Teal800 = glm::vec3(0.0, 0.411765, 0.360784);                       // #006a5c
static constexpr glm::vec3 Teal900 = glm::vec3(0.0, 0.301961, 0.25098);                        // #004e40
static constexpr glm::vec3 TealA100 = glm::vec3(0.654902, 1.0, 0.921569);                      // #a8ffec
static constexpr glm::vec3 TealA200 = glm::vec3(0.392157, 1.0, 0.854902);                      // #65ffdb
static constexpr glm::vec3 TealA400 = glm::vec3(0.113725, 0.913725, 0.713725);                 // #1de9b6
static constexpr glm::vec3 TealA700 = glm::vec3(0.0, 0.74902, 0.647059);                       // #00c0a6
                                                                                           
                                                                                           
static constexpr glm::vec3 Green50 = glm::vec3(0.909804, 0.960784, 0.913725);                  // #e9f5e9
static constexpr glm::vec3 Green100 = glm::vec3(0.784314, 0.901961, 0.788235);                 // #c9e7c9
static constexpr glm::vec3 Green200 = glm::vec3(0.647059, 0.839216, 0.654902);                 // #a6d7a8
static constexpr glm::vec3 Green300 = glm::vec3(0.505882, 0.780392, 0.517647);                 // #81c784
static constexpr glm::vec3 Green400 = glm::vec3(0.4, 0.733333, 0.415686);                      // #66bb6a
static constexpr glm::vec3 Green500 = glm::vec3(0.298039, 0.686275, 0.313725);                 // #4cb050
static constexpr glm::vec3 Green600 = glm::vec3(0.262745, 0.627451, 0.278431);                 // #43a147
static constexpr glm::vec3 Green700 = glm::vec3(0.219608, 0.556863, 0.235294);                 // #398f3c
static constexpr glm::vec3 Green800 = glm::vec3(0.180392, 0.490196, 0.196078);                 // #2e7d32
static constexpr glm::vec3 Green900 = glm::vec3(0.105882, 0.368627, 0.12549);                  // #1b5e20
static constexpr glm::vec3 GreenA100 = glm::vec3(0.72549, 0.964706, 0.792157);                 // #b9f7cb
static constexpr glm::vec3 GreenA200 = glm::vec3(0.411765, 0.941176, 0.682353);                // #6af0af
static constexpr glm::vec3 GreenA400 = glm::vec3(0.0, 0.901961, 0.462745);                     // #00e776
static constexpr glm::vec3 GreenA700 = glm::vec3(0.0, 0.784314, 0.32549);                      // #00c953
                                                                                           
                                                                                           
static constexpr glm::vec3 LightGreen50 = glm::vec3(0.945098, 0.972549, 0.913725);             // #f1f8e9
static constexpr glm::vec3 LightGreen100 = glm::vec3(0.862745, 0.929412, 0.784314);            // #dceec9
static constexpr glm::vec3 LightGreen200 = glm::vec3(0.772549, 0.882353, 0.647059);            // #c5e2a6
static constexpr glm::vec3 LightGreen300 = glm::vec3(0.682353, 0.835294, 0.505882);            // #afd581
static constexpr glm::vec3 LightGreen400 = glm::vec3(0.611765, 0.8, 0.396078);                 // #9dcc65
static constexpr glm::vec3 LightGreen500 = glm::vec3(0.545098, 0.764706, 0.290196);            // #8bc44a
static constexpr glm::vec3 LightGreen600 = glm::vec3(0.486275, 0.701961, 0.258824);            // #7db443
static constexpr glm::vec3 LightGreen700 = glm::vec3(0.407843, 0.623529, 0.219608);            // #689f39
static constexpr glm::vec3 LightGreen800 = glm::vec3(0.333333, 0.545098, 0.184314);            // #558b30
static constexpr glm::vec3 LightGreen900 = glm::vec3(0.2, 0.411765, 0.117647);                 // #336a1e
static constexpr glm::vec3 LightGreenA100 = glm::vec3(0.8, 1.0, 0.564706);                     // #ccff91
static constexpr glm::vec3 LightGreenA200 = glm::vec3(0.698039, 1.0, 0.34902);                 // #b2ff5a
static constexpr glm::vec3 LightGreenA400 = glm::vec3(0.462745, 1.0, 0.011765);                // #76ff04
static constexpr glm::vec3 LightGreenA700 = glm::vec3(0.392157, 0.866667, 0.090196);           // #65de17
                                                                                           
                                                                                           
static constexpr glm::vec3 Lime50 = glm::vec3(0.976471, 0.984314, 0.905882);                   // #fafce7
static constexpr glm::vec3 Lime100 = glm::vec3(0.941176, 0.956863, 0.764706);                  // #f0f5c4
static constexpr glm::vec3 Lime200 = glm::vec3(0.901961, 0.933333, 0.611765);                  // #e7ee9d
static constexpr glm::vec3 Lime300 = glm::vec3(0.862745, 0.905882, 0.458824);                  // #dce776
static constexpr glm::vec3 Lime400 = glm::vec3(0.831373, 0.882353, 0.341176);                  // #d5e257
static constexpr glm::vec3 Lime500 = glm::vec3(0.803922, 0.862745, 0.223529);                  // #cedc39
static constexpr glm::vec3 Lime600 = glm::vec3(0.752941, 0.792157, 0.2);                       // #c0cb33
static constexpr glm::vec3 Lime700 = glm::vec3(0.686275, 0.705882, 0.168627);                  // #b0b42b
static constexpr glm::vec3 Lime800 = glm::vec3(0.619608, 0.615686, 0.141176);                  // #9f9d24
static constexpr glm::vec3 Lime900 = glm::vec3(0.509804, 0.466667, 0.090196);                  // #837817
static constexpr glm::vec3 LimeA100 = glm::vec3(0.956863, 1.0, 0.505882);                      // #f5ff81
static constexpr glm::vec3 LimeA200 = glm::vec3(0.933333, 1.0, 0.254902);                      // #eeff42
static constexpr glm::vec3 LimeA400 = glm::vec3(0.776471, 1.0, 0.0);                           // #c7ff00
static constexpr glm::vec3 LimeA700 = glm::vec3(0.682353, 0.917647, 0.0);                      // #afea00
                                                                                           
                                                                                           
static constexpr glm::vec3 Yellow50 = glm::vec3(1.0, 0.992157, 0.905882);                      // #fffee7
static constexpr glm::vec3 Yellow100 = glm::vec3(1.0, 0.976471, 0.768627);                     // #fffac4
static constexpr glm::vec3 Yellow200 = glm::vec3(1.0, 0.960784, 0.615686);                     // #fff59d
static constexpr glm::vec3 Yellow300 = glm::vec3(1.0, 0.945098, 0.462745);                     // #fff176
static constexpr glm::vec3 Yellow400 = glm::vec3(1.0, 0.933333, 0.345098);                     // #ffee58
static constexpr glm::vec3 Yellow500 = glm::vec3(1.0, 0.921569, 0.231373);                     // #ffec3c
static constexpr glm::vec3 Yellow600 = glm::vec3(0.992157, 0.847059, 0.207843);                // #fed935
static constexpr glm::vec3 Yellow700 = glm::vec3(0.984314, 0.752941, 0.176471);                // #fcc02e
static constexpr glm::vec3 Yellow800 = glm::vec3(0.976471, 0.658824, 0.145098);                // #faa925
static constexpr glm::vec3 Yellow900 = glm::vec3(0.960784, 0.498039, 0.090196);                // #f57f17
static constexpr glm::vec3 YellowA100 = glm::vec3(1.0, 1.0, 0.552941);                         // #ffff8d
static constexpr glm::vec3 YellowA200 = glm::vec3(1.0, 1.0, 0.0);                              // #ffff00
static constexpr glm::vec3 YellowA400 = glm::vec3(1.0, 0.917647, 0.0);                         // #ffea00
static constexpr glm::vec3 YellowA700 = glm::vec3(1.0, 0.839216, 0.0);                         // #ffd700
                                                                                           
                                                                                           
static constexpr glm::vec3 Amber50 = glm::vec3(1.0, 0.972549, 0.882353);                       // #fff8e2
static constexpr glm::vec3 Amber100 = glm::vec3(1.0, 0.92549, 0.701961);                       // #ffecb4
static constexpr glm::vec3 Amber200 = glm::vec3(1.0, 0.878431, 0.509804);                      // #ffe083
static constexpr glm::vec3 Amber300 = glm::vec3(1.0, 0.835294, 0.309804);                      // #ffd550
static constexpr glm::vec3 Amber400 = glm::vec3(1.0, 0.792157, 0.156863);                      // #ffcb29
static constexpr glm::vec3 Amber500 = glm::vec3(1.0, 0.756863, 0.027451);                      // #ffc208
static constexpr glm::vec3 Amber600 = glm::vec3(1.0, 0.701961, 0.0);                           // #ffb400
static constexpr glm::vec3 Amber700 = glm::vec3(1.0, 0.627451, 0.0);                           // #ffa100
static constexpr glm::vec3 Amber800 = glm::vec3(1.0, 0.560784, 0.0);                           // #ff8f00
static constexpr glm::vec3 Amber900 = glm::vec3(1.0, 0.435294, 0.0);                           // #ff6f00
static constexpr glm::vec3 AmberA100 = glm::vec3(1.0, 0.898039, 0.498039);                     // #ffe57f
static constexpr glm::vec3 AmberA200 = glm::vec3(1.0, 0.843137, 0.25098);                      // #ffd740
static constexpr glm::vec3 AmberA400 = glm::vec3(1.0, 0.768627, 0.0);                          // #ffc400
static constexpr glm::vec3 AmberA700 = glm::vec3(1.0, 0.670588, 0.0);                          // #ffab00
                                                                                           
                                                                                           
static constexpr glm::vec3 Orange50 = glm::vec3(1.0, 0.952941, 0.878431);                      // #fff3e0
static constexpr glm::vec3 Orange100 = glm::vec3(1.0, 0.878431, 0.698039);                     // #ffe0b2
static constexpr glm::vec3 Orange200 = glm::vec3(1.0, 0.8, 0.501961);                          // #ffcc81
static constexpr glm::vec3 Orange300 = glm::vec3(1.0, 0.717647, 0.301961);                     // #ffb74e
static constexpr glm::vec3 Orange400 = glm::vec3(1.0, 0.654902, 0.14902);                      // #ffa827
static constexpr glm::vec3 Orange500 = glm::vec3(1.0, 0.596078, 0.0);                          // #ff9800
static constexpr glm::vec3 Orange600 = glm::vec3(0.984314, 0.54902, 0.0);                      // #fc8d00
static constexpr glm::vec3 Orange700 = glm::vec3(0.960784, 0.486275, 0.0);                     // #f57d00
static constexpr glm::vec3 Orange800 = glm::vec3(0.937255, 0.423529, 0.0);                     // #f06c00
static constexpr glm::vec3 Orange900 = glm::vec3(0.901961, 0.317647, 0.0);                     // #e75100
static constexpr glm::vec3 OrangeA100 = glm::vec3(1.0, 0.819608, 0.501961);                    // #ffd281
static constexpr glm::vec3 OrangeA200 = glm::vec3(1.0, 0.670588, 0.25098);                     // #ffab40
static constexpr glm::vec3 OrangeA400 = glm::vec3(1.0, 0.568627, 0.0);                         // #ff9100
static constexpr glm::vec3 OrangeA700 = glm::vec3(1.0, 0.427451, 0.0);                         // #ff6e00
                                                                                           
                                                                                           
static constexpr glm::vec3 DeepOrange50 = glm::vec3(0.984314, 0.913725, 0.905882);             // #fce9e7
static constexpr glm::vec3 DeepOrange100 = glm::vec3(1.0, 0.8, 0.737255);                      // #ffccbd
static constexpr glm::vec3 DeepOrange200 = glm::vec3(1.0, 0.670588, 0.568627);                 // #ffab91
static constexpr glm::vec3 DeepOrange300 = glm::vec3(1.0, 0.541176, 0.396078);                 // #ff8a65
static constexpr glm::vec3 DeepOrange400 = glm::vec3(1.0, 0.439216, 0.262745);                 // #ff7143
static constexpr glm::vec3 DeepOrange500 = glm::vec3(1.0, 0.341176, 0.133333);                 // #ff5722
static constexpr glm::vec3 DeepOrange600 = glm::vec3(0.956863, 0.317647, 0.117647);            // #f5511e
static constexpr glm::vec3 DeepOrange700 = glm::vec3(0.901961, 0.290196, 0.098039);            // #e74a19
static constexpr glm::vec3 DeepOrange800 = glm::vec3(0.847059, 0.262745, 0.082353);            // #d94316
static constexpr glm::vec3 DeepOrange900 = glm::vec3(0.74902, 0.211765, 0.047059);             // #c0370d
static constexpr glm::vec3 DeepOrangeA100 = glm::vec3(1.0, 0.619608, 0.501961);                // #ff9f81
static constexpr glm::vec3 DeepOrangeA200 = glm::vec3(1.0, 0.431373, 0.25098);                 // #ff6f40
static constexpr glm::vec3 DeepOrangeA400 = glm::vec3(1.0, 0.239216, 0.0);                     // #ff3e00
static constexpr glm::vec3 DeepOrangeA700 = glm::vec3(0.866667, 0.172549, 0.0);                // #de2c00
                                                                                           
                                                                                           
static constexpr glm::vec3 Brown50 = glm::vec3(0.937255, 0.921569, 0.913725);                  // #f0ece9
static constexpr glm::vec3 Brown100 = glm::vec3(0.843137, 0.8, 0.784314);                      // #d7ccc9
static constexpr glm::vec3 Brown200 = glm::vec3(0.737255, 0.666667, 0.643137);                 // #bdaba4
static constexpr glm::vec3 Brown300 = glm::vec3(0.631373, 0.533333, 0.498039);                 // #a2887f
static constexpr glm::vec3 Brown400 = glm::vec3(0.552941, 0.431373, 0.388235);                 // #8d6f63
static constexpr glm::vec3 Brown500 = glm::vec3(0.47451, 0.333333, 0.282353);                  // #7a5549
static constexpr glm::vec3 Brown600 = glm::vec3(0.427451, 0.298039, 0.254902);                 // #6e4c42
static constexpr glm::vec3 Brown700 = glm::vec3(0.364706, 0.25098, 0.215686);                  // #5e4037
static constexpr glm::vec3 Brown800 = glm::vec3(0.305882, 0.203922, 0.180392);                 // #4e352e
static constexpr glm::vec3 Brown900 = glm::vec3(0.243137, 0.152941, 0.137255);                 // #3e2724
                                                                                           
                                                                                           
static constexpr glm::vec3 Gray50 = glm::vec3(0.980392, 0.980392, 0.980392);                   // #fafafa
static constexpr glm::vec3 Gray100 = glm::vec3(0.960784, 0.960784, 0.960784);                  // #f5f5f5
static constexpr glm::vec3 Gray200 = glm::vec3(0.933333, 0.933333, 0.933333);                  // #eeeeee
static constexpr glm::vec3 Gray300 = glm::vec3(0.878431, 0.878431, 0.878431);                  // #e0e0e0
static constexpr glm::vec3 Gray400 = glm::vec3(0.741176, 0.741176, 0.741176);                  // #bdbdbd
static constexpr glm::vec3 Gray500 = glm::vec3(0.619608, 0.619608, 0.619608);                  // #9f9f9f
static constexpr glm::vec3 Gray600 = glm::vec3(0.458824, 0.458824, 0.458824);                  // #767676
static constexpr glm::vec3 Gray700 = glm::vec3(0.380392, 0.380392, 0.380392);                  // #616161
static constexpr glm::vec3 Gray800 = glm::vec3(0.258824, 0.258824, 0.258824);                  // #434343
static constexpr glm::vec3 Gray900 = glm::vec3(0.129412, 0.129412, 0.129412);                  // #222222
                                                                                           
                                                                                           
static constexpr glm::vec3 BlueGray50 = glm::vec3(0.92549, 0.937255, 0.945098);                // #ecf0f1
static constexpr glm::vec3 BlueGray100 = glm::vec3(0.811765, 0.847059, 0.862745);              // #d0d9dc
static constexpr glm::vec3 BlueGray200 = glm::vec3(0.690196, 0.745098, 0.772549);              // #b0bec5
static constexpr glm::vec3 BlueGray300 = glm::vec3(0.564706, 0.643137, 0.682353);              // #91a4af
static constexpr glm::vec3 BlueGray400 = glm::vec3(0.470588, 0.564706, 0.611765);              // #78919d
static constexpr glm::vec3 BlueGray500 = glm::vec3(0.376471, 0.490196, 0.545098);              // #617d8b
static constexpr glm::vec3 BlueGray600 = glm::vec3(0.329412, 0.431373, 0.478431);              // #556f7a
static constexpr glm::vec3 BlueGray700 = glm::vec3(0.270588, 0.352941, 0.392157);              // #455a65
static constexpr glm::vec3 BlueGray800 = glm::vec3(0.215686, 0.278431, 0.309804);              // #374750
static constexpr glm::vec3 BlueGray900 = glm::vec3(0.14902, 0.196078, 0.219608);               // #273239
                                                                                           
static constexpr glm::vec3 Black = glm::vec3(0);                                               // #000
static constexpr glm::vec3 White = glm::vec3(1);                                               // #fff
                                                                                           
#endif // CORE_COLORS_H
