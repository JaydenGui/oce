// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Blend_CSFunction_HeaderFile
#define _Blend_CSFunction_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Blend_AppFunction.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <math_Vector.hxx>
#include <Standard_Real.hxx>
class Standard_DomainError;
class math_Matrix;
class gp_Pnt;
class gp_Pnt2d;
class gp_Vec;
class gp_Vec2d;
class TColStd_Array1OfReal;
class TColStd_Array1OfInteger;
class Blend_Point;
class TColgp_Array1OfPnt;
class TColgp_Array1OfVec;
class TColgp_Array1OfPnt2d;
class TColgp_Array1OfVec2d;


//! Deferred class for a function used to compute a blending
//! surface between a surface and a curve, using a guide line.
//! The vector <X> used in Value, Values and Derivatives methods
//! may be the vector of the parametric coordinates U,V,
//! W of the extremities of a section on the surface  and
//! the curve.
class Blend_CSFunction  : public Blend_AppFunction
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Returns 3 (default value). Can be redefined.
  Standard_EXPORT virtual   Standard_Integer NbVariables()  const;
  
  //! returns the number of equations of the function.
  Standard_EXPORT virtual   Standard_Integer NbEquations()  const = 0;
  
  //! computes the values <F> of the Functions for the
  //! variable <X>.
  //! Returns True if the computation was done successfully,
  //! False otherwise.
  Standard_EXPORT virtual   Standard_Boolean Value (const math_Vector& X, math_Vector& F)  = 0;
  
  //! returns the values <D> of the derivatives for the
  //! variable <X>.
  //! Returns True if the computation was done successfully,
  //! False otherwise.
  Standard_EXPORT virtual   Standard_Boolean Derivatives (const math_Vector& X, math_Matrix& D)  = 0;
  
  //! returns the values <F> of the functions and the derivatives
  //! <D> for the variable <X>.
  //! Returns True if the computation was done successfully,
  //! False otherwise.
  Standard_EXPORT virtual   Standard_Boolean Values (const math_Vector& X, math_Vector& F, math_Matrix& D)  = 0;
  
  //! Sets the value of the parameter along the guide line.
  //! This determines the plane in which the solution has
  //! to be found.
  Standard_EXPORT virtual   void Set (const Standard_Real Param)  = 0;
  
  //! Sets the bounds of the parametric interval on
  //! the guide line.
  //! This determines the derivatives in these values if the
  //! function is not Cn.
  Standard_EXPORT virtual   void Set (const Standard_Real First, const Standard_Real Last)  = 0;
  
  //! Returns in the vector Tolerance the parametric tolerance
  //! for each of the 3 variables;
  //! Tol is the tolerance used in 3d space.
  Standard_EXPORT virtual   void GetTolerance (math_Vector& Tolerance, const Standard_Real Tol)  const = 0;
  
  //! Returns in the vector InfBound the lowest values allowed
  //! for each of the 3 variables.
  //! Returns in the vector SupBound the greatest values allowed
  //! for each of the 3 variables.
  Standard_EXPORT virtual   void GetBounds (math_Vector& InfBound, math_Vector& SupBound)  const = 0;
  
  //! Returns Standard_True if Sol is a zero of the function.
  //! Tol is the tolerance used in 3d space.
  //! The computation is made at the current value of
  //! the parameter on the guide line.
  Standard_EXPORT virtual   Standard_Boolean IsSolution (const math_Vector& Sol, const Standard_Real Tol)  = 0;
  
  //! Returns   the    minimal  Distance  beetween   two
  //! extremitys of calculed sections.
  Standard_EXPORT virtual   Standard_Real GetMinimalDistance()  const;
  
  //! Returns the point on the first support.
  Standard_EXPORT  const  gp_Pnt& Pnt1()  const;
  
  //! Returns the point on the seconde support.
  Standard_EXPORT  const  gp_Pnt& Pnt2()  const;
  
  //! Returns the point on the surface.
  Standard_EXPORT virtual  const  gp_Pnt& PointOnS()  const = 0;
  
  //! Returns the point on the curve.
  Standard_EXPORT virtual  const  gp_Pnt& PointOnC()  const = 0;
  
  //! Returns U,V coordinates of the point on the surface.
  Standard_EXPORT virtual  const  gp_Pnt2d& Pnt2d()  const = 0;
  
  //! Returns parameter of the point on the curve.
  Standard_EXPORT virtual   Standard_Real ParameterOnC()  const = 0;
  
  //! Returns True when it is not possible to compute
  //! the tangent vectors at PointOnS and/or PointOnC.
  Standard_EXPORT virtual   Standard_Boolean IsTangencyPoint()  const = 0;
  
  //! Returns the tangent vector at PointOnS, in 3d space.
  Standard_EXPORT virtual  const  gp_Vec& TangentOnS()  const = 0;
  
  //! Returns the tangent vector at PointOnS, in the
  //! parametric space of the first surface.
  Standard_EXPORT virtual  const  gp_Vec2d& Tangent2d()  const = 0;
  
  //! Returns the tangent vector at PointOnC, in 3d space.
  Standard_EXPORT virtual  const  gp_Vec& TangentOnC()  const = 0;
  
  //! Returns the tangent vector at the section,
  //! at the beginning and the end of the section, and
  //! returns the normal (of the surfaces) at
  //! these points.
  Standard_EXPORT virtual   void Tangent (const Standard_Real U, const Standard_Real V, gp_Vec& TgS, gp_Vec& NormS)  const = 0;
  
  Standard_EXPORT virtual   void GetShape (Standard_Integer& NbPoles, Standard_Integer& NbKnots, Standard_Integer& Degree, Standard_Integer& NbPoles2d)  = 0;
  
  //! Returns the tolerance to reach in approximation
  //! to respecte
  //! BoundTol error at the Boundary
  //! AngleTol tangent error at the Boundary
  //! SurfTol error inside the surface.
  Standard_EXPORT virtual   void GetTolerance (const Standard_Real BoundTol, const Standard_Real SurfTol, const Standard_Real AngleTol, math_Vector& Tol3d, math_Vector& Tol1D)  const = 0;
  
  Standard_EXPORT virtual   void Knots (TColStd_Array1OfReal& TKnots)  = 0;
  
  Standard_EXPORT virtual   void Mults (TColStd_Array1OfInteger& TMults)  = 0;
  
  //! Used for the first and last section
  //! The method returns Standard_True if the derivatives
  //! are computed, otherwise it returns Standard_False.
  Standard_EXPORT virtual   Standard_Boolean Section (const Blend_Point& P, TColgp_Array1OfPnt& Poles, TColgp_Array1OfVec& DPoles, TColgp_Array1OfPnt2d& Poles2d, TColgp_Array1OfVec2d& DPoles2d, TColStd_Array1OfReal& Weigths, TColStd_Array1OfReal& DWeigths)  = 0;
  
  Standard_EXPORT virtual   void Section (const Blend_Point& P, TColgp_Array1OfPnt& Poles, TColgp_Array1OfPnt2d& Poles2d, TColStd_Array1OfReal& Weigths)  = 0;
  
  //! Used for the first and last section
  //! The method returns Standard_True if the derivatives
  //! are computed, otherwise it returns Standard_False.
  Standard_EXPORT virtual   Standard_Boolean Section (const Blend_Point& P, TColgp_Array1OfPnt& Poles, TColgp_Array1OfVec& DPoles, TColgp_Array1OfVec& D2Poles, TColgp_Array1OfPnt2d& Poles2d, TColgp_Array1OfVec2d& DPoles2d, TColgp_Array1OfVec2d& D2Poles2d, TColStd_Array1OfReal& Weigths, TColStd_Array1OfReal& DWeigths, TColStd_Array1OfReal& D2Weigths) ;




protected:





private:





};







#endif // _Blend_CSFunction_HeaderFile
