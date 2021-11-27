#include <algorithm>
#include <gtest/gtest.h>

#define private public
#include <text/generator.h>

class TextMeshBufferPackingFixture : public ::testing::Test {
    protected:
        void SetUp() override {
            quad.s0 = 2.0;
            quad.s1 = 3.0;
            quad.t0 = 5.0;
            quad.t1 = 7.0;
            quad.x0 = 11.0;
            quad.x1 = 13.0;
            quad.y0 = 17.0;
            quad.y1 = 19.0;

            context.idx_buffer = idx_buf;
            context.vertex_buffer = vert_buf;
        }

        void reset_arrays() {
            std::fill(vert_buf, vert_buf + sizeof(vert_buf) / sizeof(float_t), 0.0);
//            std::fill(idx_buf, idx_buf + sizeof(idx_buf), 0);
        }

        float_t vert_buf[64]{0};
        uint32_t idx_buf[64]{0};

        Text text;
        stbtt_aligned_quad quad{};
        TextMeshContext context = TextMeshContext(&text);
        TextMeshGenerator gen = TextMeshGenerator(context);

};

TEST_F(TextMeshBufferPackingFixture, store_quad_pos) {
    TextAttribute tightly_packed_attrib(2, 0);
    context.add_attrib(TextAttribPosition, tightly_packed_attrib);
    gen.store_quad_pos(quad, tightly_packed_attrib, vert_buf);


    // tighly packed
    ASSERT_EQ(quad.x0, vert_buf[0])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.y0, vert_buf[1])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.x0, vert_buf[2])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.y1, vert_buf[3])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.x1, vert_buf[4])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.y1, vert_buf[5])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.x1, vert_buf[6])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.y0, vert_buf[7])     << "Packing buffer tightly had an unexpected result.";


    // step packed
    reset_arrays();
    context.reset_attribs();
    TextAttribute step_packed_attrib(4, 0);
    context.add_attrib(TextAttribPosition, step_packed_attrib);
    gen.store_quad_pos(quad, step_packed_attrib, vert_buf);

    ASSERT_EQ(quad.x0, vert_buf[0])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.y0, vert_buf[1])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[2])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[3])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.x0, vert_buf[4])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.y1, vert_buf[5])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[6])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[7])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.x1, vert_buf[8])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.y1, vert_buf[9])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[10])    << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[11])    << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.x1, vert_buf[12])    << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.y0, vert_buf[13])    << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[14])    << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[15])    << "Packing buffer with a step had an unexpected result.";


    // offset
    reset_arrays();
    context.reset_attribs();
    TextAttribute offset_attrib(2, 2);
    context.add_attrib(TextAttribPosition, offset_attrib);
    gen.store_quad_pos(quad, offset_attrib, vert_buf);

    ASSERT_EQ(0,       vert_buf[0])     << "Offset packing not respected.";
    ASSERT_EQ(0,       vert_buf[1])     << "Offset packing not respected.";
    ASSERT_EQ(quad.x0, vert_buf[2])     << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.y0, vert_buf[3])     << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.x0, vert_buf[4])     << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.y1, vert_buf[5])     << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.x1, vert_buf[6])     << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.y1, vert_buf[7])     << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.x1, vert_buf[8])     << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.y0, vert_buf[9])     << "Packing buffer with an offset had an unexpected result.";


    // stride with offset
    reset_arrays();
    context.reset_attribs();
    TextAttribute stride_offset_attrib(4, 3);
    context.add_attrib(TextAttribPosition, stride_offset_attrib);
    gen.store_quad_pos(quad, stride_offset_attrib, vert_buf);

    ASSERT_EQ(0,       vert_buf[0])     << "Offset packing not respected.";
    ASSERT_EQ(0,       vert_buf[1])     << "Offset packing not respected.";
    ASSERT_EQ(0,       vert_buf[2])     << "Offset packing not respected.";
    ASSERT_EQ(quad.x0, vert_buf[3])     << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(quad.y0, vert_buf[4])     << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[5])     << "Stride packing not respected.";
    ASSERT_EQ(0,       vert_buf[6])     << "Stride packing not respected.";
    ASSERT_EQ(quad.x0, vert_buf[7])     << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(quad.y1, vert_buf[8])     << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[9])     << "Stride packing not respected.";
    ASSERT_EQ(0,       vert_buf[10])    << "Stride packing not respected.";
    ASSERT_EQ(quad.x1, vert_buf[11])    << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(quad.y1, vert_buf[12])    << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[13])    << "Stride packing not respected.";
    ASSERT_EQ(0,       vert_buf[14])    << "Stride packing not respected.";
    ASSERT_EQ(quad.x1, vert_buf[15])    << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(quad.y0, vert_buf[16])    << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[17])    << "Stride packing not respected.";
    ASSERT_EQ(0,       vert_buf[18])    << "Stride packing not respected.";
}

TEST_F(TextMeshBufferPackingFixture, store_quad_uv) {
    TextAttribute tightly_packed_attrib(2, 0);
    context.add_attrib(TextAttribPosition, tightly_packed_attrib);
    gen.store_quad_uv(quad, tightly_packed_attrib, vert_buf);


    // tighly packed
    ASSERT_EQ(quad.s0, vert_buf[0])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.t0, vert_buf[1])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.s0, vert_buf[2])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.t1, vert_buf[3])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.s1, vert_buf[4])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.t1, vert_buf[5])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.s1, vert_buf[6])     << "Packing buffer tightly had an unexpected result.";
    ASSERT_EQ(quad.t0, vert_buf[7])     << "Packing buffer tightly had an unexpected result.";


    // step packed
    reset_arrays();
    context.reset_attribs();
    TextAttribute step_packed_attrib(4, 0);
    context.add_attrib(TextAttribPosition, step_packed_attrib);
    gen.store_quad_uv(quad, step_packed_attrib, vert_buf);

    ASSERT_EQ(quad.s0, vert_buf[0])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.t0, vert_buf[1])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[2])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[3])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.s0, vert_buf[4])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.t1, vert_buf[5])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[6])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[7])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.s1, vert_buf[8])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.t1, vert_buf[9])     << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[10])    << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[11])    << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.s1, vert_buf[12])    << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(quad.t0, vert_buf[13])    << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[14])    << "Packing buffer with a step had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[15])    << "Packing buffer with a step had an unexpected result.";


    // offset
    reset_arrays();
    context.reset_attribs();
    TextAttribute offset_attrib(2, 2);
    context.add_attrib(TextAttribPosition, offset_attrib);
    gen.store_quad_uv(quad, offset_attrib, vert_buf);

    ASSERT_EQ(0,       vert_buf[0])    << "Offset packing not respected.";
    ASSERT_EQ(0,       vert_buf[1])    << "Offset packing not respected.";
    ASSERT_EQ(quad.s0, vert_buf[2])    << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.t0, vert_buf[3])    << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.s0, vert_buf[4])    << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.t1, vert_buf[5])    << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.s1, vert_buf[6])    << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.t1, vert_buf[7])    << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.s1, vert_buf[8])    << "Packing buffer with an offset had an unexpected result.";
    ASSERT_EQ(quad.t0, vert_buf[9])    << "Packing buffer with an offset had an unexpected result.";


    // stride with offset
    reset_arrays();
    context.reset_attribs();
    TextAttribute stride_offset_attrib(4, 3);
    context.add_attrib(TextAttribPosition, stride_offset_attrib);
    gen.store_quad_uv(quad, stride_offset_attrib, vert_buf);

    ASSERT_EQ(0,       vert_buf[1])    << "Offset packing not respected.";
    ASSERT_EQ(0,       vert_buf[2])    << "Offset packing not respected.";
    ASSERT_EQ(quad.s0, vert_buf[3])    << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(quad.t0, vert_buf[4])    << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[5])    << "Stride packing not respected.";
    ASSERT_EQ(0,       vert_buf[6])    << "Stride packing not respected.";
    ASSERT_EQ(quad.s0, vert_buf[7])    << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(quad.t1, vert_buf[8])    << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[9])    << "Stride packing not respected.";
    ASSERT_EQ(0,       vert_buf[10])   << "Stride packing not respected.";
    ASSERT_EQ(quad.s1, vert_buf[11])   << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(quad.t1, vert_buf[12])   << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[13])   << "Stride packing not respected.";
    ASSERT_EQ(0,       vert_buf[14])   << "Stride packing not respected.";
    ASSERT_EQ(quad.s1, vert_buf[15])   << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(quad.t0, vert_buf[16])   << "Packing buffer with a stride and an offset had an unexpected result.";
    ASSERT_EQ(0,       vert_buf[17])   << "Stride packing not respected.";
    ASSERT_EQ(0,       vert_buf[18])   << "Stride packing not respected.";
}

TEST_F(TextMeshBufferPackingFixture, store_quad) {
    context.add_attrib(TextAttribPosition, TextAttribute(2, 0));
    context.add_attrib(TextAttribUV, TextAttribute(4, 2));

    gen.store_quad(quad, context, vert_buf);

    ASSERT_EQ(quad.x0, vert_buf[0])     << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.y0, vert_buf[1])     << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.s0, vert_buf[2])     << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.t0, vert_buf[3])     << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.x0, vert_buf[4])     << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.y1, vert_buf[5])     << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.s0, vert_buf[6])     << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.t1, vert_buf[7])     << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.x1, vert_buf[8])     << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.y1, vert_buf[9])     << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.s1, vert_buf[10])    << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.t1, vert_buf[11])    << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.x1, vert_buf[12])    << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.y0, vert_buf[13])    << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.s1, vert_buf[14])    << "Interleaved packing with no step or offset had an unexpected result.";
    ASSERT_EQ(quad.t0, vert_buf[15])    << "Interleaved packing with no step or offset had an unexpected result.";
}
