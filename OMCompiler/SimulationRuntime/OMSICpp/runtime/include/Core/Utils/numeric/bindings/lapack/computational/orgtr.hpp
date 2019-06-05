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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_ORGTR_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_ORGTR_HPP

#include <boost/assert.hpp>
#include <Core/Utils/numeric/bindings/begin.hpp>
#include <Core/Utils/numeric/bindings/detail/array.hpp>
#include <Core/Utils/numeric/bindings/is_column_major.hpp>
#include <Core/Utils/numeric/bindings/is_mutable.hpp>
#include <Core/Utils/numeric/bindings/lapack/workspace.hpp>
#include <Core/Utils/numeric/bindings/remove_imaginary.hpp>
#include <Core/Utils/numeric/bindings/size.hpp>
#include <Core/Utils/numeric/bindings/stride.hpp>
#include <Core/Utils/numeric/bindings/traits/detail/utils.hpp>
#include <Core/Utils/numeric/bindings/uplo_tag.hpp>
#include <Core/Utils/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The LAPACK-backend for orgtr is the netlib-compatible backend.
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
                    template <typename UpLo>
                    inline std::ptrdiff_t orgtr(const UpLo, const fortran_int_t n, float* a,
                                                const fortran_int_t lda, const float* tau, float* work,
                                                const fortran_int_t lwork)
                    {
                        fortran_int_t info(0);
                        LAPACK_SORGTR(&lapack_option<UpLo>::value, &n, a, &lda, tau, work,
                                      &lwork, &info);
                        return info;
                    }

                    //
                    // Overloaded function for dispatching to
                    // * netlib-compatible LAPACK backend (the default), and
                    // * double value-type.
                    //
                    template <typename UpLo>
                    inline std::ptrdiff_t orgtr(const UpLo, const fortran_int_t n, double* a,
                                                const fortran_int_t lda, const double* tau, double* work,
                                                const fortran_int_t lwork)
                    {
                        fortran_int_t info(0);
                        LAPACK_DORGTR(&lapack_option<UpLo>::value, &n, a, &lda, tau, work,
                                      &lwork, &info);
                        return info;
                    }
                } // namespace detail

                //
                // Value-type based template class. Use this class if you need a type
                // for dispatching to orgtr.
                //
                template <typename Value>
                struct orgtr_impl
                {
                    typedef Value value_type;
                    typedef typename remove_imaginary<Value>::type real_type;

                    //
                    // Static member function for user-defined workspaces, that
                    // * Deduces the required arguments for dispatching to LAPACK, and
                    // * Asserts that most arguments make sense.
                    //
                    template <typename MatrixA, typename VectorTAU, typename WORK>
                    static std::ptrdiff_t invoke(const fortran_int_t n, MatrixA& a,
                                                 const VectorTAU& tau, detail::workspace1<WORK> work)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        typedef typename result_of::uplo_tag<MatrixA>::type uplo;
                        BOOST_STATIC_ASSERT((bindings::is_column_major<MatrixA>::value));
                        BOOST_STATIC_ASSERT((boost::is_same<typename remove_const<
                                                                typename bindings::value_type<MatrixA>::type>::type,
                                                            typename remove_const<typename bindings::value_type<
                                                                VectorTAU>::type>::type>::value));
                        BOOST_STATIC_ASSERT((bindings::is_mutable<MatrixA>::value));
                        BOOST_ASSERT(bindings::size(tau) >= n - 1);
                        BOOST_ASSERT(bindings::size(work.select(real_type())) >=
                            min_size_work(n));
                        BOOST_ASSERT(bindings::size_minor(a) == 1 ||
                            bindings::stride_minor(a) == 1);
                        BOOST_ASSERT(bindings::stride_major(a) >= std::max<std::ptrdiff_t>(1,
                                                                                           n));
                        BOOST_ASSERT(n >= 0);
                        return detail::orgtr(uplo(), n, bindings::begin_value(a),
                                             bindings::stride_major(a), bindings::begin_value(tau),
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
                    template <typename MatrixA, typename VectorTAU>
                    static std::ptrdiff_t invoke(const fortran_int_t n, MatrixA& a,
                                                 const VectorTAU& tau, minimal_workspace)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        typedef typename result_of::uplo_tag<MatrixA>::type uplo;
                        bindings::detail::array<real_type> tmp_work(min_size_work(n));
                        return invoke(n, a, tau, workspace(tmp_work));
                    }

                    //
                    // Static member function that
                    // * Figures out the optimal workspace requirements, and passes
                    //   the results to the user-defined workspace overload of the
                    //   invoke static member
                    // * Enables the blocked algorithm (BLAS level 3)
                    //
                    template <typename MatrixA, typename VectorTAU>
                    static std::ptrdiff_t invoke(const fortran_int_t n, MatrixA& a,
                                                 const VectorTAU& tau, optimal_workspace)
                    {
                        namespace bindings = ::boost::numeric::bindings;
                        typedef typename result_of::uplo_tag<MatrixA>::type uplo;
                        real_type opt_size_work;
                        detail::orgtr(uplo(), n, bindings::begin_value(a),
                                      bindings::stride_major(a), bindings::begin_value(tau),
                                      &opt_size_work, -1);
                        bindings::detail::array<real_type> tmp_work(
                            traits::detail::to_int(opt_size_work));
                        return invoke(n, a, tau, workspace(tmp_work));
                    }

                    //
                    // Static member function that returns the minimum size of
                    // workspace-array work.
                    //
                    static std::ptrdiff_t min_size_work(const std::ptrdiff_t n)
                    {
                        return std::max<std::ptrdiff_t>(1, n - 1);
                    }
                };


                //
                // Functions for direct use. These functions are overloaded for temporaries,
                // so that wrapped types can still be passed and used for write-access. In
                // addition, if applicable, they are overloaded for user-defined workspaces.
                // Calls to these functions are passed to the orgtr_impl classes. In the
                // documentation, most overloads are collapsed to avoid a large number of
                // prototypes which are very similar.
                //

                //
                // Overloaded function for orgtr. Its overload differs for
                // * User-defined workspace
                //
                template <typename MatrixA, typename VectorTAU, typename Workspace>
                inline typename boost::enable_if<detail::is_workspace<Workspace>,
                                                 std::ptrdiff_t>::type
                orgtr(const fortran_int_t n, MatrixA& a, const VectorTAU& tau,
                      Workspace work)
                {
                    return orgtr_impl<typename bindings::value_type<
                        MatrixA>::type>::invoke(n, a, tau, work);
                }

                //
                // Overloaded function for orgtr. Its overload differs for
                // * Default workspace-type (optimal)
                //
                template <typename MatrixA, typename VectorTAU>
                inline typename boost::disable_if<detail::is_workspace<VectorTAU>,
                                                  std::ptrdiff_t>::type
                orgtr(const fortran_int_t n, MatrixA& a, const VectorTAU& tau)
                {
                    return orgtr_impl<typename bindings::value_type<
                        MatrixA>::type>::invoke(n, a, tau, optimal_workspace());
                }
            } // namespace lapack
        } // namespace bindings
    } // namespace numeric
} // namespace boost

#endif
