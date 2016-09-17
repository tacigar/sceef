/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_VECTOR_HPP
#define SCEEF_VECTOR_HPP

namespace sceef {

template <class T, class N>
class vector
        : public sceef::vector_expression<vector<T, N> >
{

};

} 

#endif // SCEEF_VECTOR_HPP
