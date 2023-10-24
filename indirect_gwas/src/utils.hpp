#include <boost/math/distributions/students_t.hpp>
#include <Eigen/Dense>
#include <string>
#include <vector>
#include <cmath>

// Create a struct to store the columns to read
struct ColumnSpec
{
    std::string variant_id_column;
    std::string beta_column;
    std::string se_column;
    std::string sample_size_column;
};

// Create a struct to store a matrix and its row and column names
struct LabeledMatrix
{
    Eigen::MatrixXd data;
    std::vector<std::string> row_names;
    std::vector<std::string> column_names;
};

// Create a struct to store a vector and its names
struct LabeledVector
{
    Eigen::VectorXd data;
    std::vector<std::string> names;
};

struct ResultsChunk
{
    std::vector<std::string> variant_ids;
    Eigen::MatrixXd beta;
    Eigen::MatrixXd std_error;
    Eigen::MatrixXd t_statistic;
    Eigen::MatrixXd neg_log10_p_value;
    Eigen::VectorXd sample_size;
};

double compute_log_p_value(double t_statistic, unsigned int degrees_of_freedom);
