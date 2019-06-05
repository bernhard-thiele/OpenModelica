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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_HPMV_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_HPMV_HPP

#include <boost/assert.hpp>
#include <Core/Utils/numeric/bindings/begin.hpp>
#include <Core/Utils/numeric/bindings/data_order.hpp>
#include <Core/Utils/numeric/bindings/has_linear_array.hpp>
#include <Core/Utils/numeric/bindings/has_triangular_array.hpp>
#include <Core/Utils/numeric/bindings/is_mutable.hpp>
#include <Core/Utils/numeric/bindings/remove_imaginary.hpp>
#include <Core/Utils/numeric/bindings/size.hpp>
#include <Core/Utils/numeric/bindings/stride.hpp>
#include <Core/Utils/numeric/bindings/uplo_tag.hpp>
#include <Core/Utils/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The BLAS-backend is selected by defining a pre-processor variable,
//  which can be one of
// * for CBLAS, define BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
// * for CUBLAS, define BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
// * netlib-compatible BLAS is the default
//
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
#include <Core/Utils/numeric/bindings/blas/detail/cblas.h>
#include <Core/Utils/numeric/bindings/blas/detail/cblas_option.hpp>
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
#include <Core/Utils/numeric/bindings/blas/detail/cublas.h>
#include <Core/Utils/numeric/bindings/blas/detail/blas_option.hpp>
#else
#include <Core/Utils/numeric/bindings/blas/detail/blas.h>
#include <Core/Utils/numeric/bindings/blas/detail/blas_option.hpp>
#endif

namespace boost
{
    namespace numeric
    {
        namespace bindings
        {
            namespace blas
            {
                //
                // The detail namespace contains value-type-overloaded functions that
                // dispatch to the appropriate back-end BLAS-routine.
                //
                namespace detail
                {
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
                    //
                    // Overloaded function for dispatching to
                    // * CBLAS backend, and
                    // * float value-type.
//
template< typename Order, typename UpLo >
inline void hpmv( const Order, const UpLo, const int n, const float alpha,
        const float* ap, const float* x, const int incx, const float beta,
        float* y, const int incy ) {
    cblas_sspmv( cblas_option< Order >::value, cblas_option< UpLo >::value, n,
            alpha, ap, x, incx, beta, y, incy );
}

//
                    // Overloaded function for dispatching to
                    // * CBLAS backend, and
                    // * double value-type.
//
template< typename Order, typename UpLo >
inline void hpmv( const Order, const UpLo, const int n, const double alpha,
        const double* ap, const double* x, const int incx, const double beta,
        double* y, const int incy ) {
    cblas_dspmv( cblas_option< Order >::value, cblas_option< UpLo >::value, n,
            alpha, ap, x, incx, beta, y, incy );
}

//
                    // Overloaded function for dispatching to
                    // * CBLAS backend, and
                    // * complex<float> value-type.
//
template< typename Order, typename UpLo >
inline void hpmv( const Order, const UpLo, const int n,
        const std::complex<float> alpha, const std::complex<float>* ap,
        const std::complex<float>* x, const int incx,
        const std::complex<float> beta, std::complex<float>* y,
        const int incy ) {
    cblas_chpmv( cblas_option< Order >::value, cblas_option< UpLo >::value, n,
            &alpha, ap, x, incx, &beta, y, incy );
}

//
                    // Overloaded function for dispatching to
                    // * CBLAS backend, and
                    // * complex<double> value-type.
//
template< typename Order, typename UpLo >
inline void hpmv( const Order, const UpLo, const int n,
        const std::complex<double> alpha, const std::complex<double>* ap,
        const std::complex<double>* x, const int incx,
        const std::complex<double> beta, std::complex<double>* y,
        const int incy ) {
    cblas_zhpmv( cblas_option< Order >::value, cblas_option< UpLo >::value, n,
            &alpha, ap, x, incx, &beta, y, incy );
}

#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
                    //
                    // Overloaded function for dispatching to
                    // * CUBLAS backend, and
                    // * float value-type.
//
template< typename Order, typename UpLo >
inline void hpmv( const Order, const UpLo, const int n, const float alpha,
        const float* ap, const float* x, const int incx, const float beta,
        float* y, const int incy ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    cublasSspmv( blas_option< UpLo >::value, n, alpha, ap, x, incx, beta, y,
            incy );
}

//
                    // Overloaded function for dispatching to
                    // * CUBLAS backend, and
                    // * double value-type.
//
template< typename Order, typename UpLo >
inline void hpmv( const Order, const UpLo, const int n, const double alpha,
        const double* ap, const double* x, const int incx, const double beta,
        double* y, const int incy ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    cublasDspmv( blas_option< UpLo >::value, n, alpha, ap, x, incx, beta, y,
            incy );
}

//
                    // Overloaded function for dispatching to
                    // * CUBLAS backend, and
                    // * complex<float> value-type.
//
template< typename Order, typename UpLo >
inline void hpmv( const Order, const UpLo, const int n,
        const std::complex<float> alpha, const std::complex<float>* ap,
        const std::complex<float>* x, const int incx,
        const std::complex<float> beta, std::complex<float>* y,
        const int incy ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    cublasChpmv( blas_option< UpLo >::value, n, alpha, ap, x, incx, beta, y,
            incy );
}

//
                    // Overloaded function for dispatching to
                    // * CUBLAS backend, and
                    // * complex<double> value-type.
//
template< typename Order, typename UpLo >
inline void hpmv( const Order, const UpLo, const int n,
        const std::complex<double> alpha, const std::complex<double>* ap,
        const std::complex<double>* x, const int incx,
        const std::complex<double> beta, std::complex<double>* y,
        const int incy ) {
    BOOST_STATIC_ASSERT( (is_same<Order, tag::column_major>::value) );
    cublasZhpmv( blas_option< UpLo >::value, n, alpha, ap, x, incx, beta, y,
            incy );
}

#else
                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible BLAS backend (the default), and
                    // * float value-type.
                    //
                    template <typename Order, typename UpLo>
                    inline void hpmv(const Order, const UpLo, const fortran_int_t n,
                                     const float alpha, const float* ap, const float* x,
                                     const fortran_int_t incx, const float beta, float* y,
                                     const fortran_int_t incy)
                    {
                        BOOST_STATIC_ASSERT((is_same<Order, tag::column_major>::value));
                        BLAS_SSPMV(&blas_option<UpLo>::value, &n, &alpha, ap, x, &incx, &beta,
                                   y, &incy);
                    }

                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible BLAS backend (the default), and
                    // * double value-type.
                    //
                    template <typename Order, typename UpLo>
                    inline void hpmv(const Order, const UpLo, const fortran_int_t n,
                                     const double alpha, const double* ap, const double* x,
                                     const fortran_int_t incx, const double beta, double* y,
                                     const fortran_int_t incy)
                    {
                        BOOST_STATIC_ASSERT((is_same<Order, tag::column_major>::value));
                        BLAS_DSPMV(&blas_option<UpLo>::value, &n, &alpha, ap, x, &incx, &beta,
                                   y, &incy);
                    }

                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible BLAS backend (the default), and
                    // * complex<float> value-type.
                    //
                    template <typename Order, typename UpLo>
                    inline void hpmv(const Order, const UpLo, const fortran_int_t n,
                                     const std::complex<float> alpha, const std::complex<float>* ap,
                                     const std::complex<float>* x, const fortran_int_t incx,
                                     const std::complex<float> beta, std::complex<float>* y,
                                     const fortran_int_t incy)
                    {
                        BOOST_STATIC_ASSERT((is_same<Order, tag::column_major>::value));
                        BLAS_CHPMV(&blas_option<UpLo>::value, &n, &alpha, ap, x, &incx, &beta,
                                   y, &incy);
                    }

                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible BLAS backend (the default), and
                    // * complex<double> value-type.
                    //
                    template <typename Order, typename UpLo>
                    inline void hpmv(const Order, const UpLo, const fortran_int_t n,
                                     const std::complex<double> alpha, const std::complex<double>* ap,
                                     const std::complex<double>* x, const fortran_int_t incx,
                                     const std::complex<double> beta, std::complex<double>* y,
                                     const fortran_int_t incy)
                    {
                        BOOST_STATIC_ASSERT((is_same<Order, tag::column_major>::value));
                        BLAS_ZHPMV(&blas_option<UpLo>::value, &n, &alpha, ap, x, &incx, &beta,
                                   y, &incy);
                    }

#endif
                } // namespace detail

                //
                // Value-type based template class. Use this class if you need a type
                // for dispatching to hpmv.
                //
                template <typename Value>
                struct hpmv_impl
                {
                    typedef Value value_type;
                    typedef typename remove_imaginary<Value>::type real_type;
                    typedef void result_type;

                    //
                    // Static member function that
                    // * Deduces the required arguments for dispatching to BLAS, and
                    // * Asserts that most arguments make sense.
                    //
                    template <typename MatrixAP, typename VectorX, typename VectorY>
                    static result_type invoke(const value_type alpha, const MatrixAP& ap,
                                              const VectorX& x, const value_type beta, VectorY& y)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        typedef typename result_of::data_order<MatrixAP>::type order;
                        typedef typename result_of::uplo_tag<MatrixAP>::type uplo;
                        BOOST_STATIC_ASSERT((is_same<typename remove_const<
                                                         typename bindings::value_type<MatrixAP>::type>::type,
                                                     typename remove_const<typename bindings::value_type<
                                                         VectorX>::type>::type>::value));
                        BOOST_STATIC_ASSERT((is_same<typename remove_const<
                                                         typename bindings::value_type<MatrixAP>::type>::type,
                                                     typename remove_const<typename bindings::value_type<
                                                         VectorY>::type>::type>::value));
                        BOOST_STATIC_ASSERT((bindings::has_triangular_array<
                            MatrixAP>::value));
                        BOOST_STATIC_ASSERT((bindings::has_linear_array<VectorX>::value));
                        BOOST_STATIC_ASSERT((bindings::has_linear_array<VectorY>::value));
                        BOOST_STATIC_ASSERT((bindings::is_mutable<VectorY>::value));
                        detail::hpmv(order(), uplo(), bindings::size_column(ap), alpha,
                                     bindings::begin_value(ap), bindings::begin_value(x),
                                     bindings::stride(x), beta, bindings::begin_value(y),
                                     bindings::stride(y));
                    }
                };

                //
                // Functions for direct use. These functions are overloaded for temporaries,
                // so that wrapped types can still be passed and used for write-access. Calls
                // to these functions are passed to the hpmv_impl classes. In the
                // documentation, the const-overloads are collapsed to avoid a large number of
                // prototypes which are very similar.
                //

                //
                // Overloaded function for hpmv. Its overload differs for
                //
                template <typename MatrixAP, typename VectorX, typename VectorY>
                inline typename hpmv_impl<typename bindings::value_type<
                    MatrixAP>::type>::result_type
                hpmv(const typename bindings::value_type<MatrixAP>::type alpha,
                     const MatrixAP& ap, const VectorX& x,
                     const typename bindings::value_type<MatrixAP>::type beta,
                     VectorY& y)
                {
                    hpmv_impl<typename bindings::value_type<
                        MatrixAP>::type>::invoke(alpha, ap, x, beta, y);
                }
            } // namespace blas
        } // namespace bindings
    } // namespace numeric
} // namespace boost

#endif
