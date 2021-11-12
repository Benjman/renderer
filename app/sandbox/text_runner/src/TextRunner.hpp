#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <core/memory/memory_zone.h>
#include <core/window.h>
#include <text/font.h>
#include <core/file.h>
#include <core/runner.h>
#include <core/memory.h>
#include <shader.h>
#include <text.h>

#include <iostream>

class TextRunner : public Runner {
	public:
		TextRunner(GLFWwindow *window, const uint32_t width, const uint32_t height) : Runner(window, width, height) {
			File vert = load_file(RES_PATH(shaders/text.vert));
			File frag = load_file(RES_PATH(shaders/text.frag));

			Shader shader;
			shader.load((const char*) vert.buffer, vert.size, (const char*) frag.buffer, frag.size);
			shader.use();
            vao.bind();

			load_font(font, RES_PATH(fonts/DejaVuSans.ttf));

			Texture texture(GL_TEXTURE_2D, 0, GL_RED, Font::ATLAS_WIDTH, Font::ATLAS_HEIGHT, 0, GL_RED, GL_UNSIGNED_BYTE);
            texture.bind();
            texture.upload(font.atlas_data);
			texture.parameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			texture.parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);

            size_t v_size = 0,
                   idx_size = 0;

            text.calc_sizes(&v_size, &idx_size);

            text.generate_mesh(vert_memory.ptr, idx_memory.ptr, window::width(), window::height());

            vbo.storeData(vert_memory.ptr, v_size);
			ebo.storeData(idx_memory.ptr, idx_size);

            vao.createAttribute(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) 0);
            vao.createAttribute(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) (2 * sizeof(GLfloat)));

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

	protected:
		void init(const RunnerContext& context) override {
		}

		void update(const RunnerContext& context) override {
		}

		void render() override {
            glClear(GL_COLOR_BUFFER_BIT);
			glDrawElements(GL_TRIANGLES, IDX_COUNT * text.renderable_char_count, GL_UNSIGNED_INT, 0);
		}

		void windowSizeChanged(int width, int height) override {
		}

	private:
		// TODO fixme pointer hell below
        Font font;
        Text text = Text::create("rutrum tellus pellentesque eu tincidunt tortor aliquam nulla facilisi cras fermentum odio eu feugiat pretium nibh ipsum consequat nisl vel pretium lectus quam id leo in vitae turpis massa sed elementum tempus egestas sed sed risus pretium quam vulputate dignissim suspendisse in est ante in nibh mauris cursus mattis molestie a iaculis at erat pellentesque adipiscing commodo elit at imperdiet dui accumsan sit amet nulla facilisi morbi tempus iaculis urna id volutpat lacus laoreet non curabitur gravida arcu ac tortor dignissim convallis aenean et tortor at risus viverra adipiscing at in tellus integer feugiat scelerisque varius morbi enim nunc faucibus", &font)
            .line_height(32)
            .max_width(window::width())
            .max_height(window::height())
            .alignment(TEXT_ALIGN_LEFT);

		Vao vao = Vao();
		Vbo vbo = Vbo(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
        Vbo ebo = Vbo(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW);

        MemoryZone<float_t> vert_memory = MemoryZone<float_t>(nullptr, MEGABYTES(2));
        MemoryZone<uint32_t> idx_memory = MemoryZone<uint32_t>(nullptr, MEGABYTES(2));

};

#endif // SIMULATION_HPP
