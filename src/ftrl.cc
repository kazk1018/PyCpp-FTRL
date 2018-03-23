#include "ftrl.h"

namespace ftrl {

void FTRL::Fit(const CsrMatrix &x, const DenseVector &y) {
    for (int i = 0; i < x.rows(); i++) {
        SparseVector feature = x.row(i);
        double label = (y(i) <= 0.0 ? 0.0:1.0);

        double grad = Predict(feature) - label;

        for (SparseVector::InnerIterator it(feature); it; ++it) {
            int j = it.index();
            double v = it.value();

            double g = grad * v;
            double sigma = (sqrt(n_(j) + g * g) - sqrt(n_(j))) / alpha_;
            z_(j) = z_(j) + g - sigma * w_(j);
            n_(j) = n_(j) + g * g;
        }

        for (SparseVector::InnerIterator it(feature); it; ++it) {
            int j = it.index();

            double s = Sign(z_(j));
            if (s * z_(j) < l1_) {
                w_(j) = 0.0;
            } else {
                w_(j) = (s * l1_ - z_(j)) / ((beta_ + sqrt(n_(j))) / alpha_ + l2_);
            }
        }
    }
};

} // namespace ftrl
