#ifndef CORE_MATH_H
#define CORE_MATH_H

#include <cmath>
#include <cstdint>

namespace math {

    /**
     * Re-maps a number from one range to another.
     * @param value         incoming value to be converted
     * @param current_lower bound of the value's current range
     * @param current_upper bound of the value's current range
     * @param target_lower  bound of the value's target range
     * @param target_upper  bound of the value's target range
     * @return
     */
    template<typename T>
    inline T map(T value, T current_lower, T current_upper, T target_lower, T target_upper) {
          return (value - current_lower) / (current_upper - current_lower) * (target_upper - target_lower) + target_lower;
    }

    /**
     * Re-maps a number from one range to another.
     * @param value         incoming value to be converted
     * @param current_lower bound of the value's current range
     * @param current_upper bound of the value's current range
     * @param target_lower  bound of the value's target range
     * @param target_upper  bound of the value's target range
     * @return
     */
    inline float_t map(float_t value, float_t current_lower, float_t current_upper, float_t target_lower, float_t target_upper) {
        return map<float_t>(value, current_lower, current_upper, target_lower, target_upper);
    }

    /**
     * Re-maps a number from one range to another.
     * @param value         incoming value to be converted
     * @param current_lower bound of the value's current range
     * @param current_upper bound of the value's current range
     * @param target_lower  bound of the value's target range
     * @param target_upper  bound of the value's target range
     * @return
     */
    inline double_t map(double_t value, double_t current_lower, double_t current_upper, double_t target_lower, double_t target_upper) {
        return map<double_t>(value, current_lower, current_upper, target_lower, target_upper);
    }

    /**
     * Re-maps a number from one range to another.
     * @param value         incoming value to be converted
     * @param current_lower bound of the value's current range
     * @param current_upper bound of the value's current range
     * @param target_lower  bound of the value's target range
     * @param target_upper  bound of the value's target range
     * @return
     */
    inline int32_t map(int32_t value, int32_t current_lower, int32_t current_upper, int32_t target_lower, int32_t target_upper) {
        return map<int32_t>(value, current_lower, current_upper, target_lower, target_upper);
    }

    /**
     * Re-maps a number from one range to another.
     * @param value         incoming value to be converted
     * @param current_lower bound of the value's current range
     * @param current_upper bound of the value's current range
     * @param target_lower  bound of the value's target range
     * @param target_upper  bound of the value's target range
     * @return
     */
    inline uint32_t map(uint32_t value, uint32_t current_lower, uint32_t current_upper, uint32_t target_lower, uint32_t target_upper) {
        return map<uint32_t>(value, current_lower, current_upper, target_lower, target_upper);
    }

}

#endif // CORE_MATH_H
