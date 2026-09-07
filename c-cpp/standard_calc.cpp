#include "stdbool.h"
#include "standard_calc.h"

/**
 * @brief Bounds the provided angle between [-180, 180) degrees.
 *
 * e.g.)
 *      bound_to_180(135) = 135.0
 *      bound_to_180(200) = -160.0
 *
 * @param angle: The input angle in degrees.
 *
 * @return float: The bounded angle in degrees.
 */
float bound_to_180(float angle) {
    boundedAngle = angle%360; //writes the angle as a positive number >= 0 && < 360

    if (boundedAngle >= 180){
        boundedAngle = (boundedAngle - 360);
    }
    
    return boundedAngle;
}

/**
 * @brief Determines whether an angle is between two other angles
 *
 *  e.g.)
 *      is_angle_between(0, 45, 90) = true
 *      is_angle_between(45, 90, 270) = false
 * 
 * @param first_angle:  The first bounding angle in degrees.
 * @param middle_angle: The angle in question in degrees.
 * @param second_angle: The second bounding angle in degrees.
 * @return bool: TRUE when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, FALSE otherwise
 */
bool is_angle_between(float first_angle, float middle_angle, float second_angle) {

    first_angle = bound_to_180(first_angle);
    middle_angle = bound_to_180(middle_angle);
    second_angle = bound_to_180(second_angle);

    float high_angle = max(first_angle, second_angle);
    float low_angle = min(first_angle, second_angle);

    if ((high_angle-low_angle)<=180){
        return (low_angle<=middle_angle && middle_angle<=high_angle);
    } else if ((high_angle-low_angle)<=180){
        return !(low_angle<=middle_angle && middle_angle<=high_angle);
    }
}
