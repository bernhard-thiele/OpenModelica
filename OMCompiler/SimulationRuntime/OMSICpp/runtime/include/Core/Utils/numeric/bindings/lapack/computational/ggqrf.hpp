//
// Copyright (c) 2002--2010
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_GGQRF_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_GGQRF_HPP

#include <boost/assert.hpp>
#include <Core/Utils/numeric/bindings/begin.hpp>
#include <Core/Utils/numeric/bindings/detail/array.hpp>
#include <Core/Utils/numeric/bindings/is_column_major.hpp>
#include <Core/Utils/numeric/bindings/is_complex.hpp>
#include <Core/Utils/numeric/bindings/is_mutable.hpp>
#include <Core/Utils/numeric/bindings/is_real.hpp>
#include <Core/Utils/numeric/bindings/lapack/workspace.hpp>
#include <Core/Utils/numeric/bindings/remove_imaginary.hpp>
#include <Core/Utils/numeric/bindings/size.hpp>
#include <Core/Utils/numeric/bindings/stride.hpp>
#include <Core/Utils/numeric/bindings/traits/detail/utils.hpp>
#include <Core/Utils/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/utility/enable_if.hpp>

//
// The LAPACK-backend for ggqrf is the netlib-compatible backend.
//
#include <Core/Utils/numeric/bindings/lapack/detail/lapack.h>
#include <Core/Utils/numeric/bindings/lapack/detail/lapack_option.hpp>

namespace boost
{
    namespace numeric
    {
        namespace bindings
        {
            namespace lapack
            {
                //
                // The detail namespace contains value-type-overloaded functions that
                // dispatch to the appropriate back-end LAPACK-routine.
                //
                namespace detail
                {
                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible LAPACK backend (the default), and
                    // * float value-type.
                    //
                    inline std::ptrdiff_t ggqrf(const fortran_int_t n, const fortran_int_t m,
                                                const fortran_int_t p, float* a, const fortran_int_t lda, float* taua,
                                                float* b, const fortran_int_t ldb, float* taub, float* work,
                                                const fortran_int_t lwork)
                    {
                        fortran_int_t info(0);
                        LAPACK_SGGQRF(&n, &m, &p, a, &lda, taua, b, &ldb, taub, work, &lwork,
                                      &info);
                        return info;
                    }

                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible LAPACK backend (the default), and
                    // * double value-type.
                    //
                    inline std::ptrdiff_t ggqrf(const fortran_int_t n, const fortran_int_t m,
                                                const fortran_int_t p, double* a, const fortran_int_t lda,
                                                double* taua, double* b, const fortran_int_t ldb, double* taub,
                                                double* work, const fortran_int_t lwork)
                    {
                        fortran_int_t info(0);
                        LAPACK_DGGQRF(&n, &m, &p, a, &lda, taua, b, &ldb, taub, work, &lwork,
                                      &info);
                        return info;
                    }

                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible LAPACK backend (the default), and
                    // * complex<float> value-type.
                    //
                    inline std::ptrdiff_t ggqrf(const fortran_int_t n, const fortran_int_t m,
                                                const fortran_int_t p, std::complex<float>* a,
                                                const fortran_int_t lda, std::complex<float>* taua,
                                                std::complex<float>* b, const fortran_int_t ldb,
                                                std::complex<float>* taub, std::complex<float>* work,
                                                const fortran_int_t lwork)
                    {
                        fortran_int_t info(0);
                        LAPACK_CGGQRF(&n, &m, &p, a, &lda, taua, b, &ldb, taub, work, &lwork,
                                      &info);
                        return info;
                    }

                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible LAPACK backend (the default), and
                    // * complex<double> value-type.
                    //
                    inline std::ptrdiff_t ggqrf(const fortran_int_t n, const fortran_int_t m,
                                                const fortran_int_t p, std::complex<double>* a,
                                                const fortran_int_t lda, std::complex<double>* taua,
                                                std::complex<double>* b, const fortran_int_t ldb,
                                                std::complex<double>* taub, std::complex<double>* work,
                                                const fortran_int_t lwork)
                    {
                        fortran_int_t info(0);
                        LAPACK_ZGGQRF(&n, &m, &p, a, &lda, taua, b, &ldb, taub, work, &lwork,
                                      &info);
                        return info;
                    }
                } // namespace detail

                //
                // Value-type based template class. Use this class if you need a type
                // for dispatching to ggqrf.
                //
                template <typename Value, typename Enable = void>
                struct ggqrf_impl
                {
                };

                //
                // This implementation is enabled if Value is a real type.
                //
                template <typename Value>
                struct ggqrf_impl<Value, typename boost::enable_if<is_real<Value>>::type>
                {
                    typedef Value value_type;
                    typedef typename remove_imaginary<Value>::type real_type;

                    //
                    // Static member function for user-defined workspaces, that
                    // * Deduces the required arguments for dispatching to LAPACK, and
                    // * Asserts that most arguments make sense.
                    //
                    template <typename MatrixA, typename VectorTAUA, typename MatrixB,
                              typename VectorTAUB, typename WORK>
                    static std::ptrdiff_t invoke(MatrixA& a, VectorTAUA& taua, MatrixB& b,
                                                 VectorTAUB& taub, detail::workspace1<WORK> work)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        BOOST_STATIC_ASSERT((bindings::is_column_major<MatrixA>::value));
                        BOOST_STATIC_ASSERT((bindings::is_column_major<MatrixB>::value));
                        BOOST_STATIC_ASSERT((boost::is_same<typename remove_const<
                                                                typename bindings::value_type<MatrixA>::type>::type,
                                                            typename remove_const<typename bindings::value_type<
                                                                VectorTAUA>::type>::type>::value));
                        BOOST_STATIC_ASSERT((boost::is_same<typename remove_const<
                                                                typename bindings::value_type<MatrixA>::type>::type,
                                                            typename remove_const<typename bindings::value_type<
                                                                MatrixB>::type>::type>::value));
                        BOOST_STATIC_ASSERT((boost::is_same<typename remove_const<
                                                                typename bindings::value_type<MatrixA>::type>::type,
                                                            typename remove_const<typename bindings::value_type<
                                                                VectorTAUB>::type>::type>::value));
                        BOOST_STATIC_ASSERT((bindings::is_mutable<MatrixA>::value));
                        BOOST_STATIC_ASSERT((bindings::is_mutable<VectorTAUA>::value));
                        BOOST_STATIC_ASSERT((bindings::is_mutable<MatrixB>::value));
                        BOOST_STATIC_ASSERT((bindings::is_mutable<VectorTAUB>::value));
                        BOOST_ASSERT(bindings::size(taua) >= std::min<
                            std::ptrdiff_t>(bindings::size_row(a),
                                            bindings::size_column(a)));
                        BOOST_ASSERT(bindings::size(taub) >= std::min<
                            std::ptrdiff_t>(bindings::size_row(a),
                                            bindings::size_column(b)));
                        BOOST_ASSERT(bindings::size(work.select(real_type())) >=
                            min_size_work(bindings::size_row(a),
                                          bindings::size_column(a), bindings::size_column(b)));
                        BOOST_ASSERT(bindings::size_column(a) >= 0);
                        BOOST_ASSERT(bindings::size_column(b) >= 0);
                        BOOST_ASSERT(bindings::size_minor(a) == 1 ||
                            bindings::stride_minor(a) == 1);
                        BOOST_ASSERT(bindings::size_minor(b) == 1 ||
                            bindings::stride_minor(b) == 1);
                        BOOST_ASSERT(bindings::size_row(a) >= 0);
                        BOOST_ASSERT(bindings::stride_major(a) >= std::max<std::ptrdiff_t>(1,
                                                                                           bindings::size_row(a)));
                        BOOST_ASSERT(bindings::stride_major(b) >= std::max<std::ptrdiff_t>(1,
                                                                                           bindings::size_row(a)));
                        return detail::ggqrf(bindings::size_row(a), bindings::size_column(a),
                                             bindings::size_column(b), bindings::begin_value(a),
                                             bindings::stride_major(a), bindings::begin_value(taua),
                                             bindings::begin_value(b), bindings::stride_major(b),
                                             bindings::begin_value(taub),
                                             bindings::begin_value(work.select(real_type())),
                                             bindings::size(work.select(real_type())));
                    }

                    //
                    // Static member function that
                    // * Figures out the minimal workspace requirements, and passes
                    //   the results to the user-defined workspace overload of the
                    //   invoke static member function
                    // * Enables the unblocked algorithm (BLAS level 2)
                    //
                    template <typename MatrixA, typename VectorTAUA, typename MatrixB,
                              typename VectorTAUB>
                    static std::ptrdiff_t invoke(MatrixA& a, VectorTAUA& taua, MatrixB& b,
                                                 VectorTAUB& taub, minimal_workspace)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        bindings::detail::array<real_type> tmp_work(min_size_work(
                            bindings::size_row(a), bindings::size_column(a),
                            bindings::size_column(b)));
                        return invoke(a, taua, b, taub, workspace(tmp_work));
                    }

                    //
                    // Static member function that
                    // * Figures out the optimal workspace requirements, and passes
                    //   the results to the user-defined workspace overload of the
                    //   invoke static member
                    // * Enables the blocked algorithm (BLAS level 3)
                    //
                    template <typename MatrixA, typename VectorTAUA, typename MatrixB,
                              typename VectorTAUB>
                    static std::ptrdiff_t invoke(MatrixA& a, VectorTAUA& taua, MatrixB& b,
                                                 VectorTAUB& taub, optimal_workspace)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        real_type opt_size_work;
                        detail::ggqrf(bindings::size_row(a), bindings::size_column(a),
                                      bindings::size_column(b), bindings::begin_value(a),
                                      bindings::stride_major(a), bindings::begin_value(taua),
                                      bindings::begin_value(b), bindings::stride_major(b),
                                      bindings::begin_value(taub), &opt_size_work, -1);
                        bindings::detail::array<real_type> tmp_work(
                            traits::detail::to_int(opt_size_work));
                        return invoke(a, taua, b, taub, workspace(tmp_work));
                    }

                    //
                    // Static member function that returns the minimum size of
                    // workspace-array work.
                    //
                    static std::ptrdiff_t min_size_work(const std::ptrdiff_t n,
                                                        const std::ptrdiff_t m, const std::ptrdiff_t p)
                    {
                        return std::max<std::ptrdiff_t>(1, std::max<std::ptrdiff_t>(n,
                                                                                    std::max<std::ptrdiff_t>(m, p)));
                    }
                };

                //
                // This implementation is enabled if Value is a complex type.
                //
                template <typename Value>
                struct ggqrf_impl<Value, typename boost::enable_if<is_complex<Value>>::type>
                {
                    typedef Value value_type;
                    typedef typename remove_imaginary<Value>::type real_type;

                    //
                    // Static member function for user-defined workspaces, that
                    // * Deduces the required arguments for dispatching to LAPACK, and
                    // * Asserts that most arguments make sense.
                    //
                    template <typename MatrixA, typename VectorTAUA, typename MatrixB,
                              typename VectorTAUB, typename WORK>
                    static std::ptrdiff_t invoke(MatrixA& a, VectorTAUA& taua, MatrixB& b,
                                                 VectorTAUB& taub, detail::workspace1<WORK> work)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        BOOST_STATIC_ASSERT((bindings::is_column_major<MatrixA>::value));
                        BOOST_STATIC_ASSERT((bindings::is_column_major<MatrixB>::value));
                        BOOST_STATIC_ASSERT((boost::is_same<typename remove_const<
                                                                typename bindings::value_type<MatrixA>::type>::type,
                                                            typename remove_const<typename bindings::value_type<
                                                                VectorTAUA>::type>::type>::value));
                        BOOST_STATIC_ASSERT((boost::is_same<typename remove_const<
                                                                typename bindings::value_type<MatrixA>::type>::type,
                                                            typename remove_const<typename bindings::value_type<
                                                                MatrixB>::type>::type>::value));
                        BOOST_STATIC_ASSERT((boost::is_same<typename remove_const<
                                                                typename bindings::value_type<MatrixA>::type>::type,
                                                            typename remove_const<typename bindings::value_type<
                                                                VectorTAUB>::type>::type>::value));
                        BOOST_STATIC_ASSERT((bindings::is_mutable<MatrixA>::value));
                        BOOST_STATIC_ASSERT((bindings::is_mutable<VectorTAUA>::value));
                        BOOST_STATIC_ASSERT((bindings::is_mutable<MatrixB>::value));
                        BOOST_STATIC_ASSERT((bindings::is_mutable<VectorTAUB>::value));
                        BOOST_ASSERT(bindings::size(taua) >= std::min<
                            std::ptrdiff_t>(bindings::size_row(a),
                                            bindings::size_column(a)));
                        BOOST_ASSERT(bindings::size(taub) >= std::min<
                            std::ptrdiff_t>(bindings::size_row(a),
                                            bindings::size_column(b)));
                        BOOST_ASSERT(bindings::size(work.select(value_type())) >=
                            min_size_work(bindings::size_row(a),
                                          bindings::size_column(a), bindings::size_column(b)));
                        BOOST_ASSERT(bindings::size_column(a) >= 0);
                        BOOST_ASSERT(bindings::size_column(b) >= 0);
                        BOOST_ASSERT(bindings::size_minor(a) == 1 ||
                            bindings::stride_minor(a) == 1);
                        BOOST_ASSERT(bindings::size_minor(b) == 1 ||
                            bindings::stride_minor(b) == 1);
                        BOOST_ASSERT(bindings::size_row(a) >= 0);
                        BOOST_ASSERT(bindings::stride_major(a) >= std::max<std::ptrdiff_t>(1,
                                                                                           bindings::size_row(a)));
                        BOOST_ASSERT(bindings::stride_major(b) >= std::max<std::ptrdiff_t>(1,
                                                                                           bindings::size_row(a)));
                        return detail::ggqrf(bindings::size_row(a), bindings::size_column(a),
                                             bindings::size_column(b), bindings::begin_value(a),
                                             bindings::stride_major(a), bindings::begin_value(taua),
                                             bindings::begin_value(b), bindings::stride_major(b),
                                             bindings::begin_value(taub),
                                             bindings::begin_value(work.select(value_type())),
                                             bindings::size(work.select(value_type())));
                    }

                    //
                    // Static member function that
                    // * Figures out the minimal workspace requirements, and passes
                    //   the results to the user-defined workspace overload of the
                    //   invoke static member function
                    // * Enables the unblocked algorithm (BLAS level 2)
                    //
                    template <typename MatrixA, typename VectorTAUA, typename MatrixB,
                              typename VectorTAUB>
                    static std::ptrdiff_t invoke(MatrixA& a, VectorTAUA& taua, MatrixB& b,
                                                 VectorTAUB& taub, minimal_workspace)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        bindings::detail::array<value_type> tmp_work(min_size_work(
                            bindings::size_row(a), bindings::size_column(a),
                            bindings::size_column(b)));
                        return invoke(a, taua, b, taub, workspace(tmp_work));
                    }

                    //
                    // Static member function that
                    // * Figures out the optimal workspace requirements, and passes
                    //   the results to the user-defined workspace overload of the
                    //   invoke static member
                    // * Enables the blocked algorithm (BLAS level 3)
                    //
                    template <typename MatrixA, typename VectorTAUA, typename MatrixB,
                              typename VectorTAUB>
                    static std::ptrdiff_t invoke(MatrixA& a, VectorTAUA& taua, MatrixB& b,
                                                 VectorTAUB& taub, optimal_workspace)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        value_type opt_size_work;
                        detail::ggqrf(bindings::size_row(a), bindings::size_column(a),
                                      bindings::size_column(b), bindings::begin_value(a),
                                      bindings::stride_major(a), bindings::begin_value(taua),
                                      bindings::begin_value(b), bindings::stride_major(b),
                                      bindings::begin_value(taub), &opt_size_work, -1);
                        bindings::detail::array<value_type> tmp_work(
                            traits::detail::to_int(opt_size_work));
                        return invoke(a, taua, b, taub, workspace(tmp_work));
                    }

                    //
                    // Static member function that returns the minimum size of
                    // workspace-array work.
                    //
                    static std::ptrdiff_t min_size_work(const std::ptrdiff_t n,
                                                        const std::ptrdiff_t m, const std::ptrdiff_t p)
                    {
                        return std::max<std::ptrdiff_t>(1, std::max<std::ptrdiff_t>(n,
                                                                                    std::max<std::ptrdiff_t>(m, p)));
                    }
                };


                //
                // Functions for direct use. These functions are overloaded for temporaries,
                // so that wrapped types can still be passed and used for write-access. In
                // addition, if applicable, they are overloaded for user-defined workspaces.
                // Calls to these functions are passed to the ggqrf_impl classes. In the
                // documentation, most overloads are collapsed to avoid a large number of
                // prototypes which are very similar.
                //

                //
                // Overloaded function for ggqrf. Its overload differs for
                // * User-defined workspace
                //
                template <typename MatrixA, typename VectorTAUA, typename MatrixB,
                          typename VectorTAUB, typename Workspace>
                inline typename boost::enable_if<detail::is_workspace<Workspace>,
                                                 std::ptrdiff_t>::type
                ggqrf(MatrixA& a, VectorTAUA& taua, MatrixB& b, VectorTAUB& taub,
                      Workspace work)
                {
                    return ggqrf_impl<typename bindings::value_type<
                        MatrixA>::type>::invoke(a, taua, b, taub, work);
                }

                //
                // Overloaded function for ggqrf. Its overload differs for
                // * Default workspace-type (optimal)
                //
                template <typename MatrixA, typename VectorTAUA, typename MatrixB,
                          typename VectorTAUB>
                inline typename boost::disable_if<detail::is_workspace<VectorTAUB>,
                                                  std::ptrdiff_t>::type
                ggqrf(MatrixA& a, VectorTAUA& taua, MatrixB& b, VectorTAUB& taub)
                {
                    return ggqrf_impl<typename bindings::value_type<
                        MatrixA>::type>::invoke(a, taua, b, taub, optimal_workspace());
                }
            } // namespace lapack
        } // namespace bindings
    } // namespace numeric
} // namespace boost

#endif
