/* File: _cobylamodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Sun Jan 27 18:03:18 2013
 * $Revision:$
 * $Date:$
 * Do not edit this file directly unless you know what you are doing!!!
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <setjmp.h>
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *_cobyla_error;
static PyObject *_cobyla_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
typedef void(*cb_calcfc_in__cobyla__user__routines_typedef)(int *,int *,double *,double *,double *);

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif

#define PRINTPYOBJERR(obj)\
  fprintf(stderr,"_cobyla.error is related to ");\
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");

#define GETSCALARFROMPYTUPLE(tuple,index,var,ctype,mess) {\
    if ((capi_tmp = PyTuple_GetItem((tuple),(index)))==NULL) goto capi_fail;\
    if (!(ctype ## _from_pyobj((var),capi_tmp,mess)))\
      goto capi_fail;\
  }

#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (((PyArrayObject *)(capi_ ## var ## _tmp))->nd)
#define old_shape(var,dim) (((PyArrayObject *)(capi_ ## var ## _tmp))->dimensions[dim])
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define CHECKSCALAR(check,tcheck,name,show,var)\
  if (!(check)) {\
    char errstring[256];\
    sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
    PyErr_SetString(_cobyla_error,errstring);\
    /*goto capi_fail;*/\
  } else 
#define SWAP(a,b,t) {\
  t *c;\
  c = a;\
  a = b;\
  b = c;}


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int double_from_pyobj(double* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyFloat_Check(obj)) {
#ifdef __sgi
    *v = PyFloat_AsDouble(obj);
#else
    *v = PyFloat_AS_DOUBLE(obj);
#endif
    return 1;
  }
  tmp = PyNumber_Float(obj);
  if (tmp) {
#ifdef __sgi
    *v = PyFloat_AsDouble(tmp);
#else
    *v = PyFloat_AS_DOUBLE(tmp);
#endif
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = _cobyla_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyInt_Check(obj)) {
    *v = (int)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Int(obj);
  if (tmp) {
    *v = PyInt_AS_LONG(tmp);
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = _cobyla_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}

static int create_cb_arglist(PyObject* fun,PyTupleObject* xa,const int maxnofargs,const int nofoptargs,int *nofargs,PyTupleObject **args,const char *errmess) {
  PyObject *tmp = NULL;
  PyObject *tmp_fun = NULL;
  int tot,opt,ext,siz,i,di=0;
  CFUNCSMESS("create_cb_arglist\n");
  tot=opt=ext=siz=0;
  /* Get the total number of arguments */
  if (PyFunction_Check(fun))
    tmp_fun = fun;
  else {
    di = 1;
    if (PyObject_HasAttrString(fun,"im_func")) {
      tmp_fun = PyObject_GetAttrString(fun,"im_func");
    }
    else if (PyObject_HasAttrString(fun,"__call__")) {
      tmp = PyObject_GetAttrString(fun,"__call__");
      if (PyObject_HasAttrString(tmp,"im_func"))
        tmp_fun = PyObject_GetAttrString(tmp,"im_func");
      else {
        tmp_fun = fun; /* built-in function */
        tot = maxnofargs;
        if (xa != NULL)
          tot += PyTuple_Size((PyObject *)xa);
      }
      Py_XDECREF(tmp);
    }
    else if (PyFortran_Check(fun) || PyFortran_Check1(fun)) {
      tot = maxnofargs;
      if (xa != NULL)
        tot += PyTuple_Size((PyObject *)xa);
      tmp_fun = fun;
    }
    else if (F2PyCapsule_Check(fun)) {
      tot = maxnofargs;
      if (xa != NULL)
        ext = PyTuple_Size((PyObject *)xa);
      if(ext>0) {
        fprintf(stderr,"extra arguments tuple cannot be used with CObject call-back\n");
        goto capi_fail;
      }
      tmp_fun = fun;
    }
  }
if (tmp_fun==NULL) {
fprintf(stderr,"Call-back argument must be function|instance|instance.__call__|f2py-function but got %s.\n",(fun==NULL?"NULL":Py_TYPE(fun)->tp_name));
goto capi_fail;
}
#if PY_VERSION_HEX >= 0x03000000
  if (PyObject_HasAttrString(tmp_fun,"__code__")) {
    if (PyObject_HasAttrString(tmp = PyObject_GetAttrString(tmp_fun,"__code__"),"co_argcount"))
#else
  if (PyObject_HasAttrString(tmp_fun,"func_code")) {
    if (PyObject_HasAttrString(tmp = PyObject_GetAttrString(tmp_fun,"func_code"),"co_argcount"))
#endif
      tot = PyInt_AsLong(PyObject_GetAttrString(tmp,"co_argcount")) - di;
    Py_XDECREF(tmp);
  }
  /* Get the number of optional arguments */
#if PY_VERSION_HEX >= 0x03000000
  if (PyObject_HasAttrString(tmp_fun,"__defaults__"))
    if (PyTuple_Check(tmp = PyObject_GetAttrString(tmp_fun,"__defaults__")))
#else
  if (PyObject_HasAttrString(tmp_fun,"func_defaults"))
    if (PyTuple_Check(tmp = PyObject_GetAttrString(tmp_fun,"func_defaults")))
#endif
      opt = PyTuple_Size(tmp);
    Py_XDECREF(tmp);
  /* Get the number of extra arguments */
  if (xa != NULL)
    ext = PyTuple_Size((PyObject *)xa);
  /* Calculate the size of call-backs argument list */
  siz = MIN(maxnofargs+ext,tot);
  *nofargs = MAX(0,siz-ext);
#ifdef DEBUGCFUNCS
  fprintf(stderr,"debug-capi:create_cb_arglist:maxnofargs(-nofoptargs),tot,opt,ext,siz,nofargs=%d(-%d),%d,%d,%d,%d,%d\n",maxnofargs,nofoptargs,tot,opt,ext,siz,*nofargs);
#endif
  if (siz<tot-opt) {
    fprintf(stderr,"create_cb_arglist: Failed to build argument list (siz) with enough arguments (tot-opt) required by user-supplied function (siz,tot,opt=%d,%d,%d).\n",siz,tot,opt);
    goto capi_fail;
  }
  /* Initialize argument list */
  *args = (PyTupleObject *)PyTuple_New(siz);
  for (i=0;i<*nofargs;i++) {
    Py_INCREF(Py_None);
    PyTuple_SET_ITEM((PyObject *)(*args),i,Py_None);
  }
  if (xa != NULL)
    for (i=(*nofargs);i<siz;i++) {
      tmp = PyTuple_GetItem((PyObject *)xa,i-(*nofargs));
      Py_INCREF(tmp);
      PyTuple_SET_ITEM(*args,i,tmp);
    }
  CFUNCSMESS("create_cb_arglist-end\n");
  return 1;
capi_fail:
  if ((PyErr_Occurred())==NULL)
    PyErr_SetString(_cobyla_error,errmess);
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(cobyla,COBYLA)(cb_calcfc_in__cobyla__user__routines_typedef,int*,int*,double*,double*,double*,int*,int*,double*,int*,double*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/

/******************** cb_calcfc_in__cobyla__user__routines ********************/
PyObject *cb_calcfc_in__cobyla__user__routines_capi = NULL;/*was Py_None*/
PyTupleObject *cb_calcfc_in__cobyla__user__routines_args_capi = NULL;
int cb_calcfc_in__cobyla__user__routines_nofargs = 0;
jmp_buf cb_calcfc_in__cobyla__user__routines_jmpbuf;
/*typedef void(*cb_calcfc_in__cobyla__user__routines_typedef)(int *,int *,double *,double *,double *);*/
static void cb_calcfc_in__cobyla__user__routines (int *n_cb_capi,int *m_cb_capi,double *x,double *f_cb_capi,double *con) {
  PyTupleObject *capi_arglist = cb_calcfc_in__cobyla__user__routines_args_capi;
  PyObject *capi_return = NULL;
  PyObject *capi_tmp = NULL;
  int capi_j,capi_i = 0;
  int capi_longjmp_ok = 1;
/*decl*/
  int n=(*n_cb_capi);
  int m=(*m_cb_capi);
  double f=(*f_cb_capi);
  npy_intp x_Dims[1] = {-1};
  npy_intp con_Dims[1] = {-1};
#ifdef F2PY_REPORT_ATEXIT
f2py_cb_start_clock();
#endif
  CFUNCSMESS("cb:Call-back function cb_calcfc_in__cobyla__user__routines (maxnofargs=2(-0))\n");
  CFUNCSMESSPY("cb:cb_calcfc_in__cobyla__user__routines_capi=",cb_calcfc_in__cobyla__user__routines_capi);
  if (cb_calcfc_in__cobyla__user__routines_capi==NULL) {
    capi_longjmp_ok = 0;
    cb_calcfc_in__cobyla__user__routines_capi = PyObject_GetAttrString(_cobyla_module,"calcfc");
  }
  if (cb_calcfc_in__cobyla__user__routines_capi==NULL) {
    PyErr_SetString(_cobyla_error,"cb: Callback calcfc not defined (as an argument or module _cobyla attribute).\n");
    goto capi_fail;
  }
  if (F2PyCapsule_Check(cb_calcfc_in__cobyla__user__routines_capi)) {
  cb_calcfc_in__cobyla__user__routines_typedef cb_calcfc_in__cobyla__user__routines_cptr;
  cb_calcfc_in__cobyla__user__routines_cptr = F2PyCapsule_AsVoidPtr(cb_calcfc_in__cobyla__user__routines_capi);
  (*cb_calcfc_in__cobyla__user__routines_cptr)(n_cb_capi,m_cb_capi,x,f_cb_capi,con);
  return;
  }
  if (capi_arglist==NULL) {
    capi_longjmp_ok = 0;
    capi_tmp = PyObject_GetAttrString(_cobyla_module,"calcfc_extra_args");
    if (capi_tmp) {
      capi_arglist = (PyTupleObject *)PySequence_Tuple(capi_tmp);
      if (capi_arglist==NULL) {
        PyErr_SetString(_cobyla_error,"Failed to convert _cobyla.calcfc_extra_args to tuple.\n");
        goto capi_fail;
      }
    } else {
      PyErr_Clear();
      capi_arglist = (PyTupleObject *)Py_BuildValue("()");
    }
  }
  if (capi_arglist == NULL) {
    PyErr_SetString(_cobyla_error,"Callback calcfc argument list is not set.\n");
    goto capi_fail;
  }
/*setdims*/
  x_Dims[0]=n;
  con_Dims[0]=m;
/*pyobjfrom*/
  if (cb_calcfc_in__cobyla__user__routines_nofargs>capi_i) {
    PyArrayObject *tmp_arr = (PyArrayObject *)PyArray_New(&PyArray_Type,1,x_Dims,PyArray_DOUBLE,NULL,(char*)x,0,NPY_FARRAY,NULL); /*XXX: Hmm, what will destroy this array??? */


    if (tmp_arr==NULL)
      goto capi_fail;
    if (PyTuple_SetItem((PyObject *)capi_arglist,capi_i++,(PyObject *)tmp_arr))
      goto capi_fail;
}
  if (cb_calcfc_in__cobyla__user__routines_nofargs>capi_i) {
    PyArrayObject *tmp_arr = (PyArrayObject *)PyArray_New(&PyArray_Type,1,con_Dims,PyArray_DOUBLE,NULL,(char*)con,0,NPY_FARRAY,NULL); /*XXX: Hmm, what will destroy this array??? */


    if (tmp_arr==NULL)
      goto capi_fail;
    if (PyTuple_SetItem((PyObject *)capi_arglist,capi_i++,(PyObject *)tmp_arr))
      goto capi_fail;
}
  CFUNCSMESSPY("cb:capi_arglist=",capi_arglist);
  CFUNCSMESS("cb:Call-back calling Python function calcfc.\n");
#ifdef F2PY_REPORT_ATEXIT
f2py_cb_start_call_clock();
#endif
  capi_return = PyObject_CallObject(cb_calcfc_in__cobyla__user__routines_capi,(PyObject *)capi_arglist);
#ifdef F2PY_REPORT_ATEXIT
f2py_cb_stop_call_clock();
#endif
  CFUNCSMESSPY("cb:capi_return=",capi_return);
  if (capi_return == NULL) {
    fprintf(stderr,"capi_return is NULL\n");
    goto capi_fail;
  }
  if (capi_return == Py_None) {
    Py_DECREF(capi_return);
    capi_return = Py_BuildValue("()");
  }
  else if (!PyTuple_Check(capi_return)) {
    capi_return = Py_BuildValue("(N)",capi_return);
  }
  capi_j = PyTuple_Size(capi_return);
  capi_i = 0;
/*frompyobj*/
  if (capi_j>capi_i)
    GETSCALARFROMPYTUPLE(capi_return,capi_i++,f_cb_capi,double,"double_from_pyobj failed in converting argument f of call-back function cb_calcfc_in__cobyla__user__routines to C double\n");
  CFUNCSMESS("cb:cb_calcfc_in__cobyla__user__routines:successful\n");
  Py_DECREF(capi_return);
#ifdef F2PY_REPORT_ATEXIT
f2py_cb_stop_clock();
#endif
  goto capi_return_pt;
capi_fail:
  fprintf(stderr,"Call-back cb_calcfc_in__cobyla__user__routines failed.\n");
  Py_XDECREF(capi_return);
  if (capi_longjmp_ok)
    longjmp(cb_calcfc_in__cobyla__user__routines_jmpbuf,-1);
capi_return_pt:
  ;
return;
}
/**************** end of cb_calcfc_in__cobyla__user__routines ****************/


/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************** minimize **********************************/
static char doc_f2py_rout__cobyla_minimize[] = "\
Function signature:\n\
  x,dinfo = minimize(calcfc,m,x,rhobeg,rhoend,dinfo,[iprint,maxfun,calcfc_extra_args])\n\
Required arguments:\n"
"  calcfc : call-back function\n"
"  m : input int\n"
"  x : input rank-1 array('d') with bounds (n)\n"
"  rhobeg : input float\n"
"  rhoend : input float\n"
"  dinfo : input rank-1 array('d') with bounds (4)\n"
"Optional arguments:\n"
"  calcfc_extra_args := () input tuple\n"
"  iprint := 1 input int\n"
"  maxfun := 100 input int\n"
"Return objects:\n"
"  x : rank-1 array('d') with bounds (n)\n"
"  dinfo : rank-1 array('d') with bounds (4)\n"
"Call-back functions:\n"
"  def calcfc(x,con): return f\n\
  Required arguments:\n"
"    x : input rank-1 array('d') with bounds (n)\n"
"    con : input rank-1 array('d') with bounds (m)\n"
"  Return objects:\n"
"    f : float";
/* extern void F_FUNC(cobyla,COBYLA)(cb_calcfc_in__cobyla__user__routines_typedef,int*,int*,double*,double*,double*,int*,int*,double*,int*,double*); */
static PyObject *f2py_rout__cobyla_minimize(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(cb_calcfc_in__cobyla__user__routines_typedef,int*,int*,double*,double*,double*,int*,int*,double*,int*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  PyObject *calcfc_capi = Py_None;
  PyTupleObject *calcfc_xa_capi = NULL;
  PyTupleObject *calcfc_args_capi = NULL;
  int calcfc_nofargs_capi = 0;
  cb_calcfc_in__cobyla__user__routines_typedef calcfc_cptr;
  int n = 0;
  int m = 0;
  PyObject *m_capi = Py_None;
  double *x = NULL;
  npy_intp x_Dims[1] = {-1};
  const int x_Rank = 1;
  PyArrayObject *capi_x_tmp = NULL;
  int capi_x_intent = 0;
  PyObject *x_capi = Py_None;
  double rhobeg = 0;
  PyObject *rhobeg_capi = Py_None;
  double rhoend = 0;
  PyObject *rhoend_capi = Py_None;
  int iprint = 0;
  PyObject *iprint_capi = Py_None;
  int maxfun = 0;
  PyObject *maxfun_capi = Py_None;
  double *w = NULL;
  npy_intp w_Dims[1] = {-1};
  const int w_Rank = 1;
  PyArrayObject *capi_w_tmp = NULL;
  int capi_w_intent = 0;
  int *iact = NULL;
  npy_intp iact_Dims[1] = {-1};
  const int iact_Rank = 1;
  PyArrayObject *capi_iact_tmp = NULL;
  int capi_iact_intent = 0;
  double *dinfo = NULL;
  npy_intp dinfo_Dims[1] = {-1};
  const int dinfo_Rank = 1;
  PyArrayObject *capi_dinfo_tmp = NULL;
  int capi_dinfo_intent = 0;
  PyObject *dinfo_capi = Py_None;
  static char *capi_kwlist[] = {"calcfc","m","x","rhobeg","rhoend","dinfo","iprint","maxfun","calcfc_extra_args",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOO|OOO!:_cobyla.minimize",\
    capi_kwlist,&calcfc_capi,&m_capi,&x_capi,&rhobeg_capi,&rhoend_capi,&dinfo_capi,&iprint_capi,&maxfun_capi,&PyTuple_Type,&calcfc_xa_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable rhoend */
    f2py_success = double_from_pyobj(&rhoend,rhoend_capi,"_cobyla.minimize() 5th argument (rhoend) can't be converted to double");
  if (f2py_success) {
  /* Processing variable dinfo */
  dinfo_Dims[0]=4;
  capi_dinfo_intent |= F2PY_INTENT_IN|F2PY_INTENT_OUT;
  capi_dinfo_tmp = array_from_pyobj(PyArray_DOUBLE,dinfo_Dims,dinfo_Rank,capi_dinfo_intent,dinfo_capi);
  if (capi_dinfo_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_cobyla_error,"failed in converting 6th argument `dinfo' of _cobyla.minimize to C/Fortran array" );
  } else {
    dinfo = (double *)(capi_dinfo_tmp->data);

  /* Processing variable iprint */
  if (iprint_capi == Py_None) iprint = 1; else
    f2py_success = int_from_pyobj(&iprint,iprint_capi,"_cobyla.minimize() 1st keyword (iprint) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(0<=iprint && iprint<=3,"0<=iprint && iprint<=3","1st keyword iprint","minimize:iprint=%d",iprint) {
  /* Processing variable rhobeg */
    f2py_success = double_from_pyobj(&rhobeg,rhobeg_capi,"_cobyla.minimize() 4th argument (rhobeg) can't be converted to double");
  if (f2py_success) {
  /* Processing variable m */
    f2py_success = int_from_pyobj(&m,m_capi,"_cobyla.minimize() 2nd argument (m) can't be converted to int");
  if (f2py_success) {
  /* Processing variable calcfc */
if(F2PyCapsule_Check(calcfc_capi)) {
  calcfc_cptr = F2PyCapsule_AsVoidPtr(calcfc_capi);
} else {
  calcfc_cptr = cb_calcfc_in__cobyla__user__routines;
}

  calcfc_nofargs_capi = cb_calcfc_in__cobyla__user__routines_nofargs;
  if (create_cb_arglist(calcfc_capi,calcfc_xa_capi,2,0,&cb_calcfc_in__cobyla__user__routines_nofargs,&calcfc_args_capi,"failed in processing argument list for call-back calcfc.")) {
    jmp_buf calcfc_jmpbuf;
    CFUNCSMESS("Saving jmpbuf for `calcfc`.\n");
    SWAP(calcfc_capi,cb_calcfc_in__cobyla__user__routines_capi,PyObject);
    SWAP(calcfc_args_capi,cb_calcfc_in__cobyla__user__routines_args_capi,PyTupleObject);
    memcpy(&calcfc_jmpbuf,&cb_calcfc_in__cobyla__user__routines_jmpbuf,sizeof(jmp_buf));
  /* Processing variable x */
  ;
  capi_x_intent |= F2PY_INTENT_IN|F2PY_INTENT_OUT;
  capi_x_tmp = array_from_pyobj(PyArray_DOUBLE,x_Dims,x_Rank,capi_x_intent,x_capi);
  if (capi_x_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_cobyla_error,"failed in converting 3rd argument `x' of _cobyla.minimize to C/Fortran array" );
  } else {
    x = (double *)(capi_x_tmp->data);

  /* Processing variable maxfun */
  if (maxfun_capi == Py_None) maxfun = 100; else
    f2py_success = int_from_pyobj(&maxfun,maxfun_capi,"_cobyla.minimize() 2nd keyword (maxfun) can't be converted to int");
  if (f2py_success) {
  /* Processing variable n */
  n = len(x);
  /* Processing variable w */
  w_Dims[0]=n*(3*n+2*m+11)+4*m+6;
  capi_w_intent |= F2PY_INTENT_CACHE|F2PY_INTENT_HIDE;
  capi_w_tmp = array_from_pyobj(PyArray_DOUBLE,w_Dims,w_Rank,capi_w_intent,Py_None);
  if (capi_w_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_cobyla_error,"failed in converting hidden `w' of _cobyla.minimize to C/Fortran array" );
  } else {
    w = (double *)(capi_w_tmp->data);

  /* Processing variable iact */
  iact_Dims[0]=m + 1;
  capi_iact_intent |= F2PY_INTENT_CACHE|F2PY_INTENT_HIDE;
  capi_iact_tmp = array_from_pyobj(PyArray_INT,iact_Dims,iact_Rank,capi_iact_intent,Py_None);
  if (capi_iact_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_cobyla_error,"failed in converting hidden `iact' of _cobyla.minimize to C/Fortran array" );
  } else {
    iact = (int *)(capi_iact_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
    if ((setjmp(cb_calcfc_in__cobyla__user__routines_jmpbuf))) {
      f2py_success = 0;
    } else {
        (*f2py_func)(calcfc_cptr,&n,&m,x,&rhobeg,&rhoend,&iprint,&maxfun,w,iact,dinfo);
    }
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("NN",capi_x_tmp,capi_dinfo_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
    Py_XDECREF(capi_iact_tmp);
  }  /*if (capi_iact_tmp == NULL) ... else of iact*/
  /* End of cleaning variable iact */
    Py_XDECREF(capi_w_tmp);
  }  /*if (capi_w_tmp == NULL) ... else of w*/
  /* End of cleaning variable w */
  /* End of cleaning variable n */
  } /*if (f2py_success) of maxfun*/
  /* End of cleaning variable maxfun */
  }  /*if (capi_x_tmp == NULL) ... else of x*/
  /* End of cleaning variable x */
    CFUNCSMESS("Restoring jmpbuf for `calcfc`.\n");
    cb_calcfc_in__cobyla__user__routines_capi = calcfc_capi;
    Py_DECREF(cb_calcfc_in__cobyla__user__routines_args_capi);
    cb_calcfc_in__cobyla__user__routines_args_capi = calcfc_args_capi;
    cb_calcfc_in__cobyla__user__routines_nofargs = calcfc_nofargs_capi;
    memcpy(&cb_calcfc_in__cobyla__user__routines_jmpbuf,&calcfc_jmpbuf,sizeof(jmp_buf));
  }
  /* End of cleaning variable calcfc */
  } /*if (f2py_success) of m*/
  /* End of cleaning variable m */
  } /*if (f2py_success) of rhobeg*/
  /* End of cleaning variable rhobeg */
  } /*CHECKSCALAR(0<=iprint && iprint<=3)*/
  } /*if (f2py_success) of iprint*/
  /* End of cleaning variable iprint */
  }  /*if (capi_dinfo_tmp == NULL) ... else of dinfo*/
  /* End of cleaning variable dinfo */
  } /*if (f2py_success) of rhoend*/
  /* End of cleaning variable rhoend */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/****************************** end of minimize ******************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"minimize",-1,{{-1}},0,(char *)F_FUNC(cobyla,COBYLA),(f2py_init_func)f2py_rout__cobyla_minimize,doc_f2py_rout__cobyla_minimize},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "_cobyla",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyObject *PyInit__cobyla(void) {
#else
#define RETVAL
PyMODINIT_FUNC init_cobyla(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = _cobyla_module = PyModule_Create(&moduledef);
#else
  m = _cobyla_module = Py_InitModule("_cobyla", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module _cobyla (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module '_cobyla' is auto-generated with f2py (version:2).\nFunctions:\n"
"  x,dinfo = minimize(calcfc,m,x,rhobeg,rhoend,dinfo,iprint=1,maxfun=100,calcfc_extra_args=())\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  _cobyla_error = PyErr_NewException ("_cobyla.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));

/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"_cobyla");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
