#pragma once
#include <vector>
#include "math/ImVec3.h"
namespace math
{
    class matrix
    {
    public:
        matrix(size_t rows, size_t columns);

        explicit matrix(const std::vector<std::vector<float>> &rows);

        [[nodiscard]] static matrix to_screen_matrix(float screenWidth, float screenHeight);

        matrix(const matrix &other);

        matrix(size_t rows, size_t columns, float *pRaw);

        matrix(matrix &&other) noexcept;

        [[nodiscard]] size_t get_rows_count() const;

        [[nodiscard]] size_t get_columns_count() const;

        [[nodiscard]] std::pair<size_t, size_t> get_size() const;

        float &at(size_t iRow, size_t iCol);

        float get_sum();

        matrix transpose();

        void set(float val);

        [[nodiscard]] const float &at(size_t iRow, size_t iCol) const;

        matrix operator*(const matrix &other) const;

        matrix operator*(float f) const;

        matrix operator*(const ImVec3 &vec3) const;

        matrix &operator*=(float f);

        matrix &operator/=(float f);

        void clear();

        [[nodiscard]] matrix strip(size_t row, size_t column) const;

        [[nodiscard]] float minor(size_t i, size_t j) const;

        [[nodiscard]] float alg_complement(size_t i, size_t j) const;

        [[nodiscard]] float det() const;

        matrix &operator=(const matrix &other);

        matrix &operator=(matrix &&other) noexcept;

        matrix operator/(float f) const;

        ~matrix();

    private:
        static float **Allocate2DArray(size_t i, size_t j);

        size_t m_iRows = 0;
        size_t m_iColumns = 0;
        float **m_ppData = nullptr;
    };
}