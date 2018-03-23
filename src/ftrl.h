#ifndef MAIN_FTRL_H
#define MAIN_FTRL_H

#include <Eigen/Core>
#include <Eigen/SparseCore>

namespace ftrl {

typedef Eigen::SparseMatrix<double, Eigen::RowMajor> CsrMatrix;
typedef Eigen::SparseVector<double> SparseVector;
typedef Eigen::VectorXd DenseVector;


class FTRL {
public:
    FTRL(const DenseVector &w, double alpha, double beta, double l1, double l2);

    void Fit(const CsrMatrix &x, const DenseVector &y);

    double Predict(const SparseVector &x) const;

    DenseVector GetWeight() const;

    ~FTRL() = default;

private:
    DenseVector w_;
    DenseVector n_;
    DenseVector z_;

    double alpha_;
    double beta_;
    double l1_;
    double l2_;
};

inline double Sign(const double &x) {
    if (x < 0) {
        return -1.0;
    } else {
        return 1.0;
    }
};

inline double Sigmoid(const double &x) {
    return 1.0 / (1.0 + exp(-x));
};

inline FTRL::FTRL(const DenseVector &w, double alpha, double beta, double l1, double l2) {
    w_ = w;
    n_ = DenseVector::Zero(w.size());
    z_ = DenseVector::Zero(w.size());

    alpha_ = alpha;
    beta_ = beta;
    l1_ = l1;
    l2_ = l2;
}

inline DenseVector FTRL::GetWeight() const {
    return w_;
};

inline double FTRL::Predict(const SparseVector &x) const {
    return Sigmoid(x.dot(w_));
};

} // namespace ftrl

#endif // MAIN_FTRL_H
