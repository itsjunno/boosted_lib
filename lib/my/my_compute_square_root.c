/*
** EPITECH PROJECT, 2025
** my_compute_square_root
** File description:
** Functions that returns the square root of argument
*/

int my_compute_square_root(int nb)
{
    int start = 0;
    int end = nb;
    int mid;
    int answer;

    if (nb < 0)
        return 0;
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == nb) {
            answer = mid;
            return answer;
        }
        if (mid * mid > nb) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0;
}
