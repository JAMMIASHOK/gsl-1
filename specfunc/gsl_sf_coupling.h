/* Author:  G. Jungman
 * RCS:     $Id$
 */
#ifndef GSL_SF_COUPLING_H_
#define GSL_SF_COUPLING_H_


int gsl_sf_coupling_3j_e(double ja, double jb, double jc,
                         double ma, double mb, double mc,
		         double * result);

int gsl_sf_coupling_6j_e(double ja, double jb, double jc,
                         double jd, double je, double jf,
			 double * result);


double gsl_sf_coupling_3j(double ja, double jb, double jc,
                          double ma, double mb, double mc);

double gsl_sf_coupling_6j(double ja, double jb, double jc,
                          double jd, double je, double jf);


int gsl_sf_coupling_3j_impl(double ja, double jb, double jc,
                            double ma, double mb, double mc,
			    double * result);

int gsl_sf_coupling_6j_impl(double ja, double jb, double jc,
                            double jd, double je, double jf,
			    double * result);


#endif  /* !GSL_SF_COUPLING_H_ */
