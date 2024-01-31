// Generated from libavfilter/opencl/transpose.cl
const char *ff_opencl_source_transpose =
"#line 1 \"libavfilter/opencl/transpose.cl\"\n"
"/*\n"
" * This file is part of FFmpeg.\n"
" *\n"
" * FFmpeg is free software; you can redistribute it and/or\n"
" * modify it under the terms of the GNU Lesser General Public\n"
" * License as published by the Free Software Foundation; either\n"
" * version 2.1 of the License, or (at your option) any later version.\n"
" *\n"
" * FFmpeg is distributed in the hope that it will be useful,\n"
" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n"
" * Lesser General Public License for more details.\n"
" *\n"
" * You should have received a copy of the GNU Lesser General Public\n"
" * License along with FFmpeg; if not, write to the Free Software\n"
" * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA\n"
" */\n"
"kernel void transpose(__write_only image2d_t dst,\n"
"                      __read_only image2d_t src,\n"
"                      int dir) {\n"
"    const sampler_t sampler = (CLK_NORMALIZED_COORDS_FALSE |\n"
"                               CLK_ADDRESS_CLAMP_TO_EDGE   |\n"
"                               CLK_FILTER_NEAREST);\n"
"\n"
"    int2 size = get_image_dim(dst);\n"
"    int x = get_global_id(0);\n"
"    int y = get_global_id(1);\n"
"\n"
"    int xin = (dir & 2) ? (size.y - 1 - y) : y;\n"
"    int yin = (dir & 1) ? (size.x - 1 - x) : x;\n"
"    float4 data = read_imagef(src, sampler, (int2)(xin, yin));\n"
"\n"
"    if (x < size.x && y < size.y)\n"
"        write_imagef(dst, (int2)(x, y), data);\n"
"}\n"
;