#ifndef SHADIC_BROADCASTING_HPP
#define SHADIC_BROADCASTING_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

namespace shadic {

class ShapeTracker {
public:
    using Shape = std::vector<size_t>;

    static Shape broadcast_shapes(const Shape& shape1, const Shape& shape2) {
        Shape result;
        size_t ndim1 = shape1.size();
        size_t ndim2 = shape2.size();
        size_t max_ndim = std::max(ndim1, ndim2);
        
        result.resize(max_ndim);
        
        for (size_t i = 0; i < max_ndim; ++i) {
            size_t dim1 = (i < max_ndim - ndim1) ? 1 : shape1[i - (max_ndim - ndim1)];
            size_t dim2 = (i < max_ndim - ndim2) ? 1 : shape2[i - (max_ndim - ndim2)];
            
            if (dim1 != dim2 && dim1 != 1 && dim2 != 1) {
                throw std::invalid_argument("Incompatible shapes for broadcasting");
            }
            
            result[i] = std::max(dim1, dim2);
        }
        
        return result;
    }
};

} // namespace shadic

#endif // SHADIC_BROADCASTING_HPP