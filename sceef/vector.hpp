/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_VECTOR_HPP
#define SCEEF_VECTOR_HPP

#include <array>

namespace sceef {

template <class T, class N>
class Vector
        : public sceef::VectorExpression<sceef::Vector<T, N> >
{
  private:
    using ContainerType = std::array<T, N>;
    
  public:
    

  private:
    ContainerType storage_;
};

} 

#endif // SCEEF_VECTOR_HPP
