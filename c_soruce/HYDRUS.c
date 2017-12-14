/* HYDRUS.F -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__11 = 11;
static integer c__1001 = 1001;
static integer c__7 = 7;
static integer c__20 = 20;
static integer c__100 = 100;
static integer c__1000 = 1000;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__5 = 5;

/* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||* */
/*                                                                      * */
/*     HYDRUS   - Numerical model of one-dimensional variably saturated * */
/*                water flow, heat transport, and transport of solutes  * */
/*                involved in sequential first-order decay reactions    * */
/*                version 7.0                                           * */
/*                                                                      * */
/*                Version coupled with user-friendly interface for      * */
/*                MS Windows environment                                * */
/*                                                                      * */
/*     Designed by J.Simunek, M. Sejna, and M. Th. van Genuchten (1996) * */
/*                                                                      * */
/*                                        Last modified: October, 2009  * */
/*                                                                      * */
/*                                                                      * */
/*     COPYRIGHT (c) 2005-9, Jiri Simunek, PC-Progress                  * */
/*                                                                      * */
/* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||* */
/* Main program */ int MAIN__(void)
{
    /* Initialized data */

    static logical lstopconv = TRUE_;
    static integer inonconv = 0;
    static integer iunit[7] = { 50,70,71,75,76,77,78 };

    /* Format strings */
    static char fmt_101[] = "(a)";

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    real r__1, r__2;
    doublereal d__1, d__2;
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer f_open(olist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(void), f_clos(cllist *);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_rsle(cilist *), e_rsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static real dtmaxa;
    extern /* Subroutine */ int tmcont_(real *, real *, real *, real *, real *
	    , real *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, real *, integer *, integer *, logical *, real *), 
	    update_(integer *, logical *, logical *, logical *, logical *, 
	    integer *, logical *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, integer *,
	     integer *), opensolutefiles_(integer *, char *, integer *, char *
	    , integer *, ftnlen, ftnlen);
    static logical ldualneq, lcentrif;
    static real rspacing;
    extern integer len_trim__(char *, ftnlen);
    extern /* Subroutine */ int dailyvar_(real *, doublereal *, real *, real *
	    );
    static real aeroterm;
    static logical lsinprec, lmassini;
    static integer idualpor;
    static real excesint;
    extern /* Subroutine */ int meteoint_(integer *, doublereal *, doublereal 
	    *, doublereal *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, logical *), massinit_(integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , real *, real *, real *, real *, logical *, logical *);
    static real trperiod;
    static logical lminstep, ldensity;
    static real crootmax[11];
    static integer imethour;
    static real rextinct;
    extern /* Subroutine */ int hysterin_(integer *, integer *, real *, 
	    integer *, real *, real *, real *, real *, integer *, real *, 
	    real *, real *, real *, real *, integer *, real *, real *, 
	    integer *, integer *, char *, ftnlen);
    static real sensflux;
    extern /* Subroutine */ int errorout_(integer *, char *, char *, integer *
	    , logical *, ftnlen, ftnlen);
    static logical lfluxout;
    static real sunhours;
    static integer i__, m;
    static doublereal p[1001], q[1001], r__[1001], s[1001], t;
    static real x[1001], cloudf_ac__, cloudf_bc__;
    static char cfilename[260];
    static integer icampbell;
    static char cdatapath[260];
    extern /* Subroutine */ int setchembc_(real *, real *, integer *, real *, 
	    real *, logical *, real *, integer *, integer *);
    static real g0[1001], g1[1001];
    static shortint i2;
    static real p0, q0[1001], q1[1001];
    static logical lmetdaily;
    static real p3;
    static integer imoistdep;
    extern /* Subroutine */ int noneqinit_(integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, real *, real *, 
	    logical *, logical *, integer *, logical *, real *, real *), 
	    exclusion_(integer *, integer *, integer *, real *, real *, real *
	    , real *, real *, real *);
    static real snowlayer, c50, ah[1001];
    static logical lvaporout;
    static doublereal tprintint;
    static real ak[1001], sunhoursn, sunhourso;
    static integer jj;
    static real ct[11], dt, wc[1001], ht, dz, rn;
    static integer ns;
    static real rr, rs;
    static integer iradiation;
    static real p3c, windheight, p2h, cropheight, r2h, tempheight, p2l, r2l;
    extern /* Subroutine */ int moistdepin_(char *, char *, integer *, 
	    integer *, integer *, integer *, real *, integer *, ftnlen, 
	    ftnlen);
    static real cap[1001], rad, r_h__, aqh, bqh, ath[1001], aks[1001], con[
	    1001], ahw[20], akw[20];
    static integer err;
    static real rkm, rgr, rnl;
    static integer dtv[8];
    static real ths[20], thr[20], rns, rst;
    static integer ilengthpath;
    static real cropheightn;
    extern /* Subroutine */ int initdualpor_(integer *, integer *, integer *, 
	    real *, real *, integer *, real *, real *, real *, real *, real *,
	     logical *), daymeteoout_(doublereal *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, logical *);
    static real area[10], rh_a__, beta[1001];
    static char date[8];
    static real htab[2000]	/* was [100][20] */;
    static integer ilai;
    static logical llai, lend;
    static real conc[11011]	/* was [11][1001] */;
    static integer ntab[20], node[100];
    static shortint iday;
    static real hold[1001], pard[220]	/* was [11][20] */, cbot[11], ampl, 
	    pecr, cnew[1001], tdep[180];
    static char time[10];
    static real hsat[20], disp[1001], hnew[1001];
    static doublereal told;
    static real aosm[11], sink[1001];
    static doublereal tatm;
    static real cumq[12];
    static logical lwat;
    static real vold[1001];
    static doublereal tmax;
    static real parw[220]	/* was [11][20] */;
    static char zone[5];
    static real ctop[11], tpar[200]	/* was [10][20] */, sorb[11011]	/* 
	    was [11][1001] */, vnew[1001], athw[20], aths[1001], thrr[1001], 
	    conr[1001], cono[1001], theq[1001], wdep[2178]	/* was [22][
	    99] */;
    static logical lupw;
    extern /* Subroutine */ int init_(real *, integer *, integer *, integer *,
	     integer *, integer *, real *, real *, integer *, integer *, real 
	    *, real *, real *, integer *, logical *, integer *, real *, real *
	    , real *, integer *, real *, real *, real *, logical *, logical *,
	     logical *, logical *, logical *, logical *, logical *, real *, 
	    integer *, integer *, integer *, real *, logical *, logical *, 
	    logical *, real *, logical *, real *, logical *, logical *, 
	    logical *, real *, real *, real *, integer *, integer *, real *, 
	    logical *, real *, real *, doublereal *, integer *, integer *, 
	    real *, logical *, logical *, integer *, real *, real *, logical *
	    , logical *, integer *, integer *, logical *, logical *, real *, 
	    logical *, real *, real *, logical *, real *, logical *, logical *
	    , logical *);
    static real tauw, spot, tolh, rtop, rbot;
    static integer nmat, nlay, iver, nobs;
    static real htop, cvch0[11], cvch1[11];
    static shortint i100th;
    static real hbot;
    extern /* Subroutine */ int hyst_(integer *, integer *, real *, real *, 
	    integer *, integer *, real *, real *, real *, real *, real *, 
	    integer *, integer *), tmin_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, real *, real *, real *, real *, real *
	    , doublereal *, doublereal *, real *, logical *, logical *, 
	    logical *, integer *, integer *, integer *, real *, integer *, 
	    logical *, integer *, logical *, integer *, doublereal *, logical 
	    *, logical *, logical *, logical *, real *, integer *);
    static real dmul, rlat, ralt, xlai, ttop, tbot;
    static integer ierr;
    static real epsi, catm, prec, dmul2, radn, gwl0l;
    static doublereal tatm1, tatm2;
    static real sorb2[11011]	/* was [11][1001] */, rado, wind, tmax1, 
	    tmin1;
    extern /* Subroutine */ int snow_(real *, real *, real *, real *, real *, 
	    real *, real *, logical *, real *, real *, integer *);
    static real cmin, evap, xlat, vtop;
    extern /* Subroutine */ int closeoutput_(doublereal *, integer *, logical 
	    *, logical *, logical *, logical *, logical *, logical *);
    static real spot1;
    extern /* Subroutine */ int updateenergy_(doublereal *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, integer *, integer *, real *, real *, 
	    real *, integer *, logical *, logical *, real *, real *, real *);
    static integer ikod, iter;
    static logical freed, atmbc, lbact, lchem;
    static real ccuma[11];
    extern integer iargc_(void);
    static integer kappa[1001];
    static real chpar[3600]	/* was [180][20] */;
    static integer kbold;
    static real cumch[110]	/* was [10][11] */;
    extern /* Subroutine */ int setbc_(doublereal *, doublereal *, real *, 
	    real *, real *, real *, real *, real *, real *, logical *, 
	    logical *, real *, real *, integer *, real *, real *, real *, 
	    logical *, logical *, integer *, logical *, integer *, logical *, 
	    logical *, real *, real *, logical *, real *, logical *, real *, 
	    real *, real *, integer *, real *, integer *, real *, logical *, 
	    logical *, logical *, real *);
    static real precc;
    static logical seepf;
    static real hseep;
    static logical lartd;
    static shortint isecs;
    static real ctemp[1001];
    static shortint iyear;
    static logical sinkf;
    static real thold[1001], cvoli[11], htemp[1001], ccumt[11];
    static shortint imins;
    static logical qgwlf, ltemp;
    extern doublereal rtime_(shortint *, shortint *, shortint *, shortint *, 
	    shortint *, shortint *);
    static doublereal tatmn;
    static real watin[1001], thnew[1001], solin[1001];
    static doublereal tinit;
    static real croot[11];
    static logical lflux;
    static real cvtop[11], cvbot[11], tempo[1001], tempn[1001];
    static logical lroot;
    static real poptm[20], sorbn[1001];
    static logical lsnow;
    static real ssink[1001];
    static logical ltort;
    static real cvchr[11], conlt[1001], convt[1001], convh[1001], vvold[1001],
	     vvnew[1001];
    static integer itcum;
    static real hroot, vroot;
    static integer iterw, iterc;
    static real wcumt, wcuma, xroot;
    static integer itort, icrop, maxit;
    static real tolth, rroot;
    static integer ktold;
    static real zintf, xconv, tconv;
    static integer numnp;
    static real xsurf;
    extern /* Subroutine */ int matin_(integer *, real *, real *, real *, 
	    real *, logical *, integer *, integer *, real *, integer *, real *
	    , real *, real *, integer *, real *, integer *, real *, real *, 
	    real *, real *, integer *, integer *, real *, logical *, integer *
	    , integer *, integer *);
    static integer ihyst;
    extern /* Subroutine */ int initw_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    real *, real *, integer *, real *, integer *);
    static doublereal rtime1;
    static real dtmax, dtmin, dtopt, sorbn2[1001];
    static doublereal tatm2o;
    static integer itmin, itmax, maxal;
    static real trmin, xrmin, xrmax;
    extern /* Subroutine */ int setrg_(integer *, real *, real *, doublereal *
	    , real *, real *, real *, real *, real *, real *, logical *, 
	    integer *, integer *, real *, real *);
    static integer ktopt, kbott;
    static real ctola, ctolr, dsurf, rsoil, geofac;
    extern /* Subroutine */ int meteo_(integer *, logical *, logical *, 
	    doublereal *, real *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, integer *, 
	    integer *, real *, real *, real *, real *, integer *, integer *, 
	    real *, real *, real *, logical *, real *, logical *, logical *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, integer *)
	    ;
    static real albedo, evapp, windn, windo, captab[2000]	/* was [100][
	    20] */, omegac, xlain;
    static logical lenbal;
    static real tmaxn, tmaxo, tminn, tmino;
    extern /* Subroutine */ int basinf_(real *, integer *, real *, real *, 
	    logical *, logical *, logical *, logical *, logical *, logical *, 
	    logical *, logical *, logical *, logical *, logical *, integer *, 
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, logical *, logical *, logical *, logical *, 
	    logical *, logical *, real *, real *, real *, integer *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, logical *,
	     logical *, real *, real *, logical *, logical *, integer *, 
	    logical *, logical *, logical *, real *, logical *, logical *, 
	    integer *);
    static logical ltable;
    extern /* Subroutine */ int chemin_(logical *, logical *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *, real *
	    , integer *, real *, real *, real *, real *, real *, real *, 
	    logical *, logical *, logical *, real *, logical *, real *, real *
	    , logical *, logical *, logical *, logical *, integer *, real *, 
	    integer *, integer *, real *, integer *, logical *, logical *, 
	    logical *, integer *, integer *);
    static integer ikappa;
    static real contab[2000]	/* was [100][20] */, thetab[2000]	/* 
	    was [100][20] */;
    static integer alevel;
    static logical lvarbc;
    static real cvchim[11];
    static integer kappao[1001];
    static real cosalf, omegas;
    static logical qdrain, lmobim[20], lhargr, botinf, convgf;
    static real retard[1001], dtmaxc;
    static logical lmeteo;
    static real omegaw;
    static integer plevel;
    static real consat[20];
    static logical lenter;
    static real sinkim[1001];
    static integer tlevel;
    static logical lstdep, lequil, lfiltr, topinf, lwtdep, wlayer, lvapor;
    static shortint imonth;
    static logical linitw;
    static integer matnum[1001];
    static logical lprint;
    static shortint ihours;
    static integer laynum[1001];
    static real subvol[10], cprevo[1001], thvold[1001];
    static logical shorto;
    static doublereal tprint[1000];
    static real thvnew[1001], strans[1001], dmoist[17160]	/* was [20][
	    11][13][6] */;
    static integer icount;
    static real dtmaxt, snowmf;
    static integer isunsh;
    static real radius;
    static integer kodtop, kodbot;
    static real hcrits, hcrita, zbotdr, basegw;
    static integer iposdr;
    static real rkhtop, rkhbot, rkvtop, rkvbot, entres, wetper;
    extern /* Subroutine */ int nodinf_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    real *, integer *, real *, real *, real *, real *, real *, real *,
	     real *, real *, integer *, integer *, integer *, real *, logical 
	    *, logical *, logical *, logical *, logical *, real *, integer *, 
	    logical *, logical *, logical *);
    static integer imodel;
    extern /* Subroutine */ int genmat_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     integer *, logical *, integer *, real *, real *, real *, integer 
	    *), setmat_(integer *, integer *, integer *, integer *, real *, 
	    real *, real *, real *, integer *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, logical *, real *, integer *, real *, integer *, real *, 
	    real *, real *, real *, real *, real *, real *, integer *, 
	    logical *, logical *, real *, real *, real *, real *, real *, 
	    real *, integer *, real *, logical *, real *, integer *, integer *
	    );
    static real dtinit;
    extern /* Subroutine */ int rootin_(real *, real *, real *, real *, real *
	    , logical *, integer *, integer *, integer *, real *, real *, 
	    integer *);
    static real trharv;
    extern /* Subroutine */ int tempin_(integer *, real *, real *, real *, 
	    integer *, real *, integer *, real *, logical *, logical *, 
	    integer *, integer *, real *, logical *, integer *);
    static integer maxitc, ktopch, kbotch;
    static real tpulse, transp, etcomb, xrootn, tmaxan, tminan, tempa, tmaxa, 
	    tmaxao, tmina, tminao, rhmean, rhmax, rhmaxn, rhmaxo;
    static doublereal tprint1;
    static real rhmin, rhminn, albedon;
    static integer ienhanc;
    static real rhmino, eamean, eameann, dtsnow, rrootd, rsoild, precd;
    extern /* Subroutine */ int sinkin_(integer *, logical *, logical *, 
	    logical *, logical *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, integer *, logical *, 
	    real *, integer *, real *, logical *, real *, real *, real *, 
	    real *, logical *, logical *, integer *), setsnk_(integer *, 
	    integer *, integer *, real *, real *, real *, real *, real *, 
	    real *, logical *, logical *, logical *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    logical *, integer *, integer *, real *, real *, logical *, real *
	    , real *, real *, real *, integer *, real *, logical *, real *, 
	    real *), profil_(integer *, integer *, real *, integer *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    logical *, integer *), nodout_(integer *, integer *, real *, real 
	    *, real *, real *, real *, real *, doublereal *, integer *, real *
	    , real *, real *, real *, integer *, integer *, real *, real *, 
	    real *, integer *, logical *, real *, logical *, logical *, real *
	    , real *, real *, real *, real *, integer *, real *, real *, real 
	    *, logical *, logical *, real *, logical *, logical *, integer *),
	     subreg_(integer *, integer *, integer *, real *, real *, real *, 
	    real *, integer *, integer *, doublereal *, real *, real *, real *
	    , logical *, real *, real *, integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, logical *, 
	    logical *, real *, real *, real *, integer *, integer *, real *, 
	    logical *, logical *, logical *, integer *, real *, real *, 
	    logical *, logical *, real *, logical *, real *, real *, logical *
	    , real *, real *, real *, integer *, real *, real *, logical *, 
	    logical *, real *, logical *, real *);
    static logical lsoladd;
    static real wvoli;
    static integer ntabmod;
    static real ainterc;
    static logical llinear[11];
    extern /* Subroutine */ int veloc_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, logical *, 
	    logical *, real *, real *, real *, real *, real *, real *, real *,
	     logical *, real *, integer *, logical *, real *);
    static real rhmeann;
    static integer hundred;
    static real shwrada;
    static logical lscreen, lomegaw;
    static real shwradb, rlwrada, rlwradb, tholdim[1001];
    extern /* Subroutine */ int meteoin_(real *, real *, real *, real *, real 
	    *, real *, real *, real *, real *, real *, integer *, integer *, 
	    real *, real *, real *, real *, integer *, real *, integer *, 
	    real *, real *, integer *, logical *, logical *, integer *, 
	    integer *, real *, real *, logical *, logical *, real *, integer *
	    );
    static logical ldayvar;
    static integer iinterc;
    static logical lsolred, leqinit;
    static doublereal tatmold;
    static integer irelhum;
    static real consmax, tperiod, rinterc, thnewim[1001];
    static logical lmosink, lprintd, lactrsu, lextrap, lmssink;
    static real radterm, rhmeano;
    static integer irootin;
    static real wtransf;
    extern /* Subroutine */ int sinprec_(doublereal *, doublereal *, 
	    doublereal *, real *, real *), date_and_time__(char *, char *, 
	    char *, integer *, ftnlen, ftnlen, ftnlen);
    static integer itemp, ngrowth;
    static real epsit, temps;
    static integer nprstep;
    static real rgrowth[5000]	/* was [1000][5] */;
    extern /* Subroutine */ int evapor_(doublereal *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     integer *, real *, logical *, real *, real *, real *, real *, 
	    real *, real *, real *, integer *);
    static real heatfl, const__;
    static integer itcumo;
    extern /* Subroutine */ int watflow_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, integer *, integer *, real *, real *, real *, 
	    doublereal *, real *, real *, real *, doublereal *, doublereal *, 
	    doublereal *, logical *, logical *, logical *, real *, real *, 
	    real *, real *, real *, real *, real *, logical *, integer *, 
	    integer *, logical *, integer *, integer *, real *, real *, 
	    integer *, real *, doublereal *, real *, logical *, real *, real *
	    , real *, real *, real *, logical *, real *, integer *, integer *,
	     real *, real *, real *, real *, real *, real *, real *, real *, 
	    integer *, integer *, logical *, real *, real *, real *, integer *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    logical *, logical *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, integer *, integer *, real *, 
	    real *, real *, real *, real *, integer *, real *, logical *, 
	    real *, integer *, integer *, logical *, real *, real *);
    static real rlamb;
    extern /* Subroutine */ int temper_(integer *, integer *, real *, real *, 
	    doublereal *, integer *, real *, real *, real *, real *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, integer *,
	     real *, integer *, real *, logical *, real *, real *, real *, 
	    real *, real *, logical *, real *, real *, real *, real *, 
	    integer *, integer *), solute_(integer *, integer *, integer *, 
	    integer *, real *, real *, doublereal *, real *, real *, integer *
	    , real *, real *, real *, real *, real *, real *, integer *, real 
	    *, integer *, real *, real *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, real *, real *, real *, real *, real *
	    , real *, real *, logical *, real *, real *, real *, real *, real 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     integer *, integer *, real *, real *, real *, logical *, logical 
	    *, logical *, real *, real *, real *, real *, real *, logical *, 
	    real *, real *, real *, real *, logical *, real *, integer *, 
	    logical *, real *, real *, real *, real *, logical *, logical *, 
	    integer *, real *, real *, real *, real *, integer *, real *, 
	    real *, logical *, real *, integer *, integer *, integer *, real *
	    , real *, integer *, real *, logical *, logical *, logical *, 
	    logical *, real *, real *, real *, real *, real *, logical *);
    static real peclet, courant;
    static integer jprint;
    extern /* Subroutine */ int tlinf_(integer *, real *, real *, real *, 
	    doublereal *, real *, integer *, integer *, integer *, real *, 
	    real *, real *, real *, real *, real *, integer *, integer *, 
	    integer *, logical *, logical *, logical *, real *, integer *, 
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *, real *, real *, 
	    logical *, integer *, real *, real *, logical *, logical *, 
	    logical *, real *, real *, real *, real *, real *, real *, 
	    integer *, real *, real *, real *, integer *, real *, real *, 
	    logical *, real *, logical *, real *, real *, logical *, real *, 
	    logical *, logical *, integer *, real *, real *, logical *, 
	    integer *, integer *, real *, real *, real *);
    static real dummy1, dummy2;
    extern /* Subroutine */ int obsnod_(doublereal *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, real *, 
	    logical *, real *, real *, real *, logical *, integer *);
    static real rlwrada1, rlwradb1;
    extern /* Subroutine */ int alinf_(doublereal *, real *, real *, real *, 
	    real *, integer *, integer *);
    static real dtold;

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 6, 0, 0, 0 };
    static cilist io___7 = { 1, 10, 0, fmt_101, 0 };
    static cilist io___362 = { 0, 6, 0, 0, 0 };
    static cilist io___393 = { 0, 6, 0, 0, 0 };
    static cilist io___394 = { 0, 5, 0, 0, 0 };
    static cilist io___425 = { 0, 6, 0, 0, 0 };
    static cilist io___426 = { 0, 5, 0, 0, 0 };
    static cilist io___430 = { 0, 6, 0, 0, 0 };
    static cilist io___431 = { 0, 5, 0, 0, 0 };


/* ####################################################################### */
/*     Procedura pro osetreni nasledujicich signalu: */
/*         - signal CTRL+C */
/*         - signal CTRK+BREAK */
/*         - abnormal termination */
/*         - floating point error */
/* ----------------------------------------------------------------------- */
/*      use MSFLIB */

/*      interface */
/*        function h_sig (signum) */
/*          !MS$ATTRIBUTES C :: h_sig */
/*          integer(4) h_sig */
/*          integer(2) signum */
/*        end function */
/*      end interface */

/*     interface */
/*        function hand_fpe (sigid, except) */
/*           !MS$ATTRIBUTES C :: hand_fpe */
/*          integer(4) hand_fpe */
/*          integer(2)  sigid, except */
/*        end function */
/*      end interface */
/* ####################################################################### */
/* ---- START gettim and getdat gnu alternative function VARABLES ---- */
/* ---- START gettim and getdat gnu alternative function VARABLES ---- */
/* ----------------------------------------------------------------------- */
/*      i4ret = SIGNALQQ(SIG$ABORT, h_sig) */
/*      i4ret = SIGNALQQ(SIG$BREAK, h_sig) */
/*      i4ret = SIGNALQQ(SIG$INT,   h_sig) */
/*      i4ret = SIGNALQQ(SIG$FPE,   hand_fpe) */
/* ----------------------------------------------------------------------- */
/*      iCount = NARGS() */
    icount = iargc_();
    if (icount > 1) {
	i2 = 1;
/*       call GETARG(i2, cDataPath, status) */
	s_wsle(&io___5);
	do_lio(&c__9, &c__1, "call GETARG, this lien was commented", (ftnlen)
		36);
	e_wsle();
    } else {
	s_copy(cfilename, "LEVEL_01.DIR", (ftnlen)260, (ftnlen)12);
	o__1.oerr = 1;
	o__1.ounit = 10;
	o__1.ofnmlen = 260;
	o__1.ofnm = cfilename;
	o__1.orl = 0;
	o__1.osta = "old";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L901;
	}
	i__1 = s_rsfe(&io___7);
	if (i__1 != 0) {
	    goto L904;
	}
	i__1 = do_fio(&c__1, cdatapath, (ftnlen)260);
	if (i__1 != 0) {
	    goto L904;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L904;
	}
	cl__1.cerr = 0;
	cl__1.cunit = 10;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ilengthpath = len_trim__(cdatapath, (ftnlen)260);
    if (ilengthpath > 247) {
	goto L930;
    }
/* Writing concatenation */
    i__2[0] = ilengthpath, a__1[0] = cdatapath;
    i__2[1] = 11, a__1[1] = "/Options.in";
    s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
    o__1.oerr = 1;
    o__1.ounit = 35;
    o__1.ofnmlen = 260;
    o__1.ofnm = cfilename;
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L998;
    }
L998:
/*     Initialization */
    init_(&cosalf, ntab, &itcum, &tlevel, &alevel, &plevel, &hroot, &vroot, &
	    iterw, &iterc, &dtmaxc, &wcumt, &wcuma, &err, &lvarbc, &c__11, 
	    croot, ccumt, ccuma, &c__1001, sink, wc, cumq, &lmeteo, &lbact, &
	    lvapor, &lenbal, &ldayvar, &lenter, &lfiltr, &tauw, &nprstep, &
	    ntabmod, &idualpor, &dtmaxt, &lextrap, &lprintd, &llai, &rextinct,
	     &ldensity, &excesint, &lminstep, &lprint, &lsnow, &snowmf, &
	    snowlayer, ctemp, &isunsh, &irelhum, &xroot, &lcentrif, &radius, &
	    gwl0l, &tprintint, &itort, &ienhanc, &hseep, &leqinit, &lsinprec, 
	    &imoistdep, &omegac, &wtransf, &ldualneq, &lflux, &icrop, &
	    irootin, &lmassini, &lmetdaily, sorb2, &lactrsu, &omegas, &spot, &
	    lomegaw, &omegaw, &lend, &lvaporout, &lfluxout);
/* Writing concatenation */
    i__2[0] = ilengthpath, a__1[0] = cdatapath;
    i__2[1] = 12, a__1[1] = "/Selector.in";
    s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
    o__1.oerr = 1;
    o__1.ounit = 30;
    o__1.ofnmlen = 260;
    o__1.ofnm = cfilename;
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L901;
    }
/* Writing concatenation */
    i__2[0] = ilengthpath, a__1[0] = cdatapath;
    i__2[1] = 12, a__1[1] = "/PROFILE.DAT";
    s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
    o__1.oerr = 1;
    o__1.ounit = 32;
    o__1.ofnmlen = 260;
    o__1.ofnm = cfilename;
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L901;
    }
/* Writing concatenation */
    i__2[0] = ilengthpath, a__1[0] = cdatapath;
    i__2[1] = 12, a__1[1] = "/I_CHECK.OUT";
    s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
    o__1.oerr = 1;
    o__1.ounit = 50;
    o__1.ofnmlen = 260;
    o__1.ofnm = cfilename;
    o__1.orl = 0;
    o__1.osta = "unknown";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L902;
    }
    if (lprint) {
/* Writing concatenation */
	i__2[0] = ilengthpath, a__1[0] = cdatapath;
	i__2[1] = 12, a__1[1] = "/RUN_INF.OUT";
	s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	o__1.oerr = 1;
	o__1.ounit = 70;
	o__1.ofnmlen = 260;
	o__1.ofnm = cfilename;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L902;
	}
/* Writing concatenation */
	i__2[0] = ilengthpath, a__1[0] = cdatapath;
	i__2[1] = 12, a__1[1] = "/T_LEVEL.OUT";
	s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	o__1.oerr = 1;
	o__1.ounit = 71;
	o__1.ofnmlen = 260;
	o__1.ofnm = cfilename;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L902;
	}
/* Writing concatenation */
	i__2[0] = ilengthpath, a__1[0] = cdatapath;
	i__2[1] = 12, a__1[1] = "/NOD_INF.OUT";
	s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	o__1.oerr = 1;
	o__1.ounit = 75;
	o__1.ofnmlen = 260;
	o__1.ofnm = cfilename;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L902;
	}
/* Writing concatenation */
	i__2[0] = ilengthpath, a__1[0] = cdatapath;
	i__2[1] = 12, a__1[1] = "/BALANCE.OUT";
	s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	o__1.oerr = 1;
	o__1.ounit = 76;
	o__1.ofnmlen = 260;
	o__1.ofnm = cfilename;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L902;
	}
/* Writing concatenation */
	i__2[0] = ilengthpath, a__1[0] = cdatapath;
	i__2[1] = 13, a__1[1] = "/OBS_NODE.OUT";
	s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	o__1.oerr = 1;
	o__1.ounit = 77;
	o__1.ofnmlen = 260;
	o__1.ofnm = cfilename;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L902;
	}
/* Writing concatenation */
	i__2[0] = ilengthpath, a__1[0] = cdatapath;
	i__2[1] = 12, a__1[1] = "/PROFILE.OUT";
	s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	o__1.oerr = 1;
	o__1.ounit = 78;
	o__1.ofnmlen = 260;
	o__1.ofnm = cfilename;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L902;
	}
    }
/*     Read input data -------------------------------------------------- */
    basinf_(&cosalf, &maxit, &tolth, &tolh, &topinf, &botinf, &shorto, &lwat, 
	    &lchem, &sinkf, &wlayer, &qgwlf, &freed, &seepf, &atmbc, &kodtop, 
	    &kodbot, &rtop, &rroot, &rbot, &hcrits, &hcrita, &gwl0l, &aqh, &
	    bqh, &ktold, &kbold, &c__7, iunit, &nmat, &c__20, &nlay, &lroot, &
	    ltemp, &lwtdep, &lequil, &lscreen, &qdrain, &zbotdr, &basegw, &
	    rspacing, &iposdr, &rkhtop, &rkhbot, &rkvtop, &rkvbot, &entres, &
	    wetper, &zintf, &geofac, &linitw, &lvarbc, &xconv, &tconv, &
	    lmeteo, &lvapor, &iver, &lprint, &lcentrif, &lsnow, &hseep, &
	    lflux, &lactrsu, &err);
    if (err != 0) {
	switch (err) {
	    case 1:  goto L905;
	    case 2:  goto L906;
	    case 3:  goto L903;
	    case 4:  goto L916;
	}
    }
    if (lprint) {
	if (lfluxout) {
/* Writing concatenation */
	    i__2[0] = ilengthpath, a__1[0] = cdatapath;
	    i__2[1] = 13, a__1[1] = "/T_Level1.OUT";
	    s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	    o__1.oerr = 1;
	    o__1.ounit = 44;
	    o__1.ofnmlen = 260;
	    o__1.ofnm = cfilename;
	    o__1.orl = 0;
	    o__1.osta = "unknown";
	    o__1.oacc = 0;
	    o__1.ofm = 0;
	    o__1.oblnk = 0;
	    i__1 = f_open(&o__1);
	    if (i__1 != 0) {
		goto L902;
	    }
	}
	if (lvaporout && lvapor) {
/* Writing concatenation */
	    i__2[0] = ilengthpath, a__1[0] = cdatapath;
	    i__2[1] = 14, a__1[1] = "/NOD_INF_V.OUT";
	    s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	    o__1.oerr = 1;
	    o__1.ounit = 45;
	    o__1.ofnmlen = 260;
	    o__1.ofnm = cfilename;
	    o__1.orl = 0;
	    o__1.osta = "unknown";
	    o__1.oacc = 0;
	    o__1.ofm = 0;
	    o__1.oblnk = 0;
	    i__1 = f_open(&o__1);
	    if (i__1 != 0) {
		goto L902;
	    }
	}
    }
    if (topinf || botinf || atmbc) {
/* Writing concatenation */
	i__2[0] = ilengthpath, a__1[0] = cdatapath;
	i__2[1] = 11, a__1[1] = "/ATMOSPH.IN";
	s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	o__1.oerr = 1;
	o__1.ounit = 31;
	o__1.ofnmlen = 260;
	o__1.ofnm = cfilename;
	o__1.orl = 0;
	o__1.osta = "old";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L901;
	}
	if (lprint) {
/* Writing concatenation */
	    i__2[0] = ilengthpath, a__1[0] = cdatapath;
	    i__2[1] = 12, a__1[1] = "/A_LEVEL.OUT";
	    s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	    o__1.oerr = 1;
	    o__1.ounit = 72;
	    o__1.ofnmlen = 260;
	    o__1.ofnm = cfilename;
	    o__1.orl = 0;
	    o__1.osta = "unknown";
	    o__1.oacc = 0;
	    o__1.ofm = 0;
	    o__1.oblnk = 0;
	    i__1 = f_open(&o__1);
	    if (i__1 != 0) {
		goto L902;
	    }
	}
	if (lmeteo) {
/* Writing concatenation */
	    i__2[0] = ilengthpath, a__1[0] = cdatapath;
	    i__2[1] = 9, a__1[1] = "/Meteo.in";
	    s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	    o__1.oerr = 1;
	    o__1.ounit = 33;
	    o__1.ofnmlen = 260;
	    o__1.ofnm = cfilename;
	    o__1.orl = 0;
	    o__1.osta = "old";
	    o__1.oacc = 0;
	    o__1.ofm = 0;
	    o__1.oblnk = 0;
	    i__1 = f_open(&o__1);
	    if (i__1 != 0) {
		goto L902;
	    }
	    if (lprint) {
/* Writing concatenation */
		i__2[0] = ilengthpath, a__1[0] = cdatapath;
		i__2[1] = 10, a__1[1] = "/Meteo.out";
		s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
		o__1.oerr = 1;
		o__1.ounit = 43;
		o__1.ofnmlen = 260;
		o__1.ofnm = cfilename;
		o__1.orl = 0;
		o__1.osta = "unknown";
		o__1.oacc = 0;
		o__1.ofm = 0;
		o__1.oblnk = 0;
		i__1 = f_open(&o__1);
		if (i__1 != 0) {
		    goto L902;
		}
	    }
	}
    }
    nodinf_(&c__1001, &numnp, &c__100, &nobs, &htop, &hbot, x, hnew, hold, 
	    matnum, htemp, laynum, beta, ah, ak, ath, conc, sorb, tempn, 
	    tempo, node, &c__11, &ns, &xsurf, &lchem, &ltemp, &lequil, &
	    lscreen, &lbact, sorb2, &err, &lprint, &ldualneq, &lflux);
    if (err != 0) {
	switch (err) {
	    case 1:  goto L912;
	    case 2:  goto L903;
	    case 3:  goto L914;
	    case 4:  goto L915;
	    case 5:  goto L929;
	}
    }
    matin_(&nmat, pard, parw, htab, &htab[ntab[0] - 1], &lscreen, &err, &
	    numnp, ah, &ihyst, ahw, athw, akw, matnum, hnew, kappa, aths, 
	    thrr, conr, aks, kappao, &imodel, &xconv, &ltable, &ikappa, &
	    ntabmod, &idualpor);
    if (err != 0) {
	switch (err) {
	    case 1:  goto L906;
	    case 2:  goto L903;
	}
    }
    if (ihyst > 0 && ihyst != 3) {
	hysterin_(&numnp, &nmat, hold, matnum, pard, parw, thnew, thold, 
		kappa, aths, thrr, cono, conr, aks, kappao, ah, ak, &ihyst, &
		imodel, cdatapath, (ftnlen)260);
    }
    if (imodel == ntabmod) {
/* Writing concatenation */
	i__2[0] = ilengthpath, a__1[0] = cdatapath;
	i__2[1] = 9, a__1[1] = "/Mater.in";
	s_cat(cfilename, a__1, i__2, &c__2, (ftnlen)260);
	o__1.oerr = 1;
	o__1.ounit = 36;
	o__1.ofnmlen = 260;
	o__1.ofnm = cfilename;
	o__1.orl = 0;
	o__1.osta = "old";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L901;
	}
    }
    if (linitw && imodel < ntabmod) {
	initw_(&numnp, &nmat, matnum, kappa, hnew, hold, htemp, pard, parw, &
		imodel, &htop, &hbot, &idualpor, thnewim, &err);
	if (err != 0) {
	    goto L924;
	}
    }
    genmat_(ntab, &c__100, &nmat, thr, ths, hsat, pard, htab, contab, captab, 
	    consat, thetab, &imodel, &lscreen, &ntabmod, &consmax, &xconv, &
	    tconv, &err);
    if (err == 1) {
	goto L903;
    }
    if (ihyst != 3) {
	setmat_(&numnp, ntab, &c__100, &nmat, htab, contab, captab, hnew, 
		matnum, pard, con, cap, consat, ah, ak, ath, hsat, htemp, 
		thetab, thold, thr, ths, &lwtdep, tempn, &iterw, cono, kappa, 
		aths, thrr, conr, aks, ahw, athw, akw, &imodel, &ltable, &
		lvapor, thvold, conlt, convt, convh, &xconv, &tconv, &ntabmod,
		 &hcrita, &ldensity, conc, &c__11, &ienhanc);
    } else {
/* Bob Lenhard hysteresis */
	hyst_(&numnp, &c__20, pard, parw, matnum, kappa, hnew, hold, thold, 
		con, cap, &ikappa, &c__1);
    }
    initdualpor_(&numnp, &nmat, matnum, pard, thold, &idualpor, thnewim, 
	    tholdim, sinkim, hnew, strans, &linitw);
    tmin_(&tinit, &tmax, &tatm, &told, &dt, &dtmax, &dmul, &dmul2, &dtmin, 
	    tprint, &t, &dtopt, &topinf, &botinf, &lscreen, &itmin, &itmax, &
	    maxal, &hcrits, &c__1000, &atmbc, &iver, &lprintd, &nprstep, &
	    tprintint, &lenter, &ldayvar, &lsinprec, &llai, &rextinct, &err);
    if (err != 0) {
	switch (err) {
	    case 1:  goto L907;
	    case 2:  goto L928;
	}
    }
    tprint1 = tmax;
    if (lprintd) {
	tprint1 = tinit + tprintint;
    }
    if (lmeteo) {
	meteoin_(&rlat, &ralt, &shwrada, &shwradb, &rlwrada, &rlwradb, &
		rlwrada1, &rlwradb1, &windheight, &tempheight, &icrop, &ilai, 
		&cropheight, &albedo, &xlai, &xroot, &iinterc, &ainterc, &
		ngrowth, rgrowth, &rextinct, &iradiation, &lenbal, &lprint, &
		isunsh, &irelhum, &cloudf_ac__, &cloudf_bc__, &lhargr, &
		lmetdaily, &xconv, &err);
	if (err != 0) {
	    switch (err) {
		case 1:  goto L932;
	    }
	}
	if (lenbal) {
	    icrop = 0;
	}
    }
    tatm2 = tmax;
    dtinit = dt;
    if (lroot) {
	rootin_(&trmin, &trharv, &xrmin, &xrmax, &rgr, &lscreen, &iver, &
		irootin, &ngrowth, rgrowth, &trperiod, &err);
	if (err != 0) {
	    switch (err) {
		case 1:  goto L908;
		case 2:  goto L903;
	    }
	}
    }
    if (lroot || icrop > 1) {
	setrg_(&numnp, x, beta, &t, &trmin, &trharv, &xrmin, &xrmax, &rgr, &
		xroot, &lroot, &irootin, &ngrowth, rgrowth, &trperiod);
    }
    if (ltemp) {
	tempin_(&nmat, tpar, &ampl, &tperiod, &ktopt, &ttop, &kbott, &tbot, &
		topinf, &botinf, &icampbell, &iver, &snowmf, &lscreen, &ierr);
	if (err != 0) {
	    switch (err) {
		case 1:  goto L910;
		case 2:  goto L903;
	    }
	}
	if (lenbal) {
	    ktopt = -1;
	}
    }
    if (lchem) {
	chemin_(&lupw, &lstdep, &nmat, &ns, &c__11, &maxitc, chpar, tdep, &
		ktopch, ctop, &kbotch, cbot, &epsi, &tpulse, cumch, &ctola, &
		ctolr, llinear, &lequil, &lartd, &pecr, &lscreen, &dsurf, &
		catm, &ltort, lmobim, &lbact, &lfiltr, &imoistdep, wdep, &
		c__20, &imodel, pard, &iver, &ldualneq, &lmassini, &leqinit, &
		itort, &err);
	if (err != 0) {
	    switch (err) {
		case 1:  goto L911;
		case 2:  goto L903;
		case 3:  goto L931;
	    }
	}
	if (idualpor > 0) {
	    lequil = FALSE_;
	}
	if (imoistdep == 2) {
	    moistdepin_(cdatapath, cfilename, &nmat, &c__20, &ns, &c__11, 
		    dmoist, &imoistdep, (ftnlen)260, (ftnlen)260);
	}
	if (lmassini) {
	    massinit_(&numnp, &c__11, &ns, &nmat, matnum, tdep, tempn, chpar, 
		    conc, thold, tholdim, ths, llinear, &lbact);
	}
	if (! lequil && (leqinit || lmassini)) {
	    noneqinit_(&numnp, &c__11, &ns, &nmat, matnum, tdep, tempo, chpar,
		     conc, sorb, llinear, lmobim, &idualpor, &lbact, sorb2, 
		    thold);
	}
	if (lprint) {
	    opensolutefiles_(&ns, cdatapath, &ilengthpath, cfilename, &err, (
		    ftnlen)260, (ftnlen)260);
	    if (err == 1) {
		goto L902;
	    }
	}
    }
    if (topinf || botinf || atmbc) {
	setbc_(&tmax, &tatm1, &rtop, &rroot, &rbot, &hcrita, &hbot, &htop, &
		gwl0l, &topinf, &botinf, ct, cbot, &ns, &ttop, &tbot, &ampl, &
		ltemp, &lchem, &kodtop, &lvarbc, &err, &lminstep, &lmeteo, &
		prec, &rsoil, &llai, &rextinct, &lcentrif, &cosalf, &xconv, &
		tconv, &imodel, &hnew[numnp - 1], &irootin, &xroot, &wlayer, 
		llinear, &lactrsu, &spot);
	if (err == 1) {
	    goto L913;
	}
	if (lmeteo) {
	    meteo_(&c__1, &lmetdaily, &ldayvar, &t, &dt, &tinit, &tmax, &
		    tatm2, &tatmn, &tatm2o, &dtmax, &rlat, &ralt, &shwrada, &
		    shwradb, &rlwrada, &rlwradb, &rlwrada1, &rlwradb1, &
		    windheight, &tempheight, &icrop, &ilai, &rroot, &xconv, &
		    tconv, rgrowth, &ngrowth, &iinterc, &rinterc, &ainterc, &
		    excesint, &lenbal, &rextinct, &lprint, &lhargr, &
		    iradiation, &isunsh, &irelhum, &imethour, &cloudf_ac__, &
		    cloudf_bc__, &prec, &precc, &rsoil, &evapp, &transp, &rns,
		     &rnl, &radterm, &aeroterm, &rst, &etcomb, &rad, &radn, &
		    rado, &wind, &windn, &windo, &albedo, &albedon, &xlai, &
		    xlain, &xroot, &xrootn, &cropheight, &cropheightn, &ampl, 
		    &ttop, &tmaxan, &tminan, &tmax1, &tmaxn, &tmaxo, &tmin1, &
		    tminn, &tmino, &tempa, &tmaxa, &tmaxao, &tmina, &tminao, &
		    sunhours, &sunhoursn, &sunhourso, &rhmean, &rhmeann, &
		    rhmeano, &rhmax, &rhmaxn, &rhmaxo, &rhmin, &rhminn, &
		    rhmino, &rh_a__, &eamean, &eameann, &rtop, &err);
	    if (err != 0) {
		switch (err) {
		    case 1:  goto L932;
		    case 2:  goto L913;
		    case 3:  goto L933;
		}
	    }
	}
	if (lchem && snowlayer <= 0.f) {
	    setchembc_(&prec, &rsoil, &ns, ctop, ct, &wlayer, &hnew[numnp - 1]
		    , &kodtop, &ktopch);
	}
	if (lsnow) {
	    dtsnow = (real) (tatm1 - tinit);
	    snow_(&prec, &dtsnow, &ttop, &snowmf, &snowlayer, &rsoil, &xconv, 
		    &lminstep, ctop, ct, &ns);
	}
	tatm = min(tatm1,tatm2);
	if (ldayvar) {
	    rrootd = rroot;
	    rsoild = rsoil;
	    dailyvar_(&tconv, &t, &rroot, &rrootd);
	    dailyvar_(&tconv, &t, &rsoil, &rsoild);
	}
	if (lsinprec) {
	    precd = prec;
	    tatmold = (real) tinit;
	    sinprec_(&t, &tatmold, &tatm1, &prec, &precd);
	}
	if (kodtop == -4) {
	    rtop = dabs(rsoil) - dabs(prec);
	}
    }
    if (sinkf) {
	sinkin_(&nmat, &lchem, &lmosink, &lsolred, &lsoladd, &p0, poptm, &p2h,
		 &p2l, &p3, &r2h, &r2l, aosm, &c50, &p3c, &ns, &lmssink, 
		crootmax, &iver, &omegac, &lactrsu, &omegas, &spot1, &rkm, &
		cmin, &lomegaw, &lscreen, &err);
	if (err != 0) {
	    switch (err) {
		case 1:  goto L909;
		case 2:  goto L903;
	    }
	}
	if (! topinf && ! botinf && ! atmbc) {
	    spot = spot1;
	}
	setsnk_(&numnp, &nmat, matnum, x, &hroot, &vroot, sink, &rroot, hnew, 
		&lmosink, &lsolred, &lsoladd, &p0, poptm, &p2h, &p2l, &p3, &
		r2h, &r2l, aosm, &c50, &p3c, beta, &lchem, &ns, &c__11, conc, 
		croot, &lmssink, thold, pard, &dt, &omegac, &imodel, con, &
		lomegaw, &omegaw, &rbot);
    }
    cl__1.cerr = 0;
    cl__1.cunit = 30;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 32;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 50;
    cl__1.csta = 0;
    f_clos(&cl__1);
    if (lprint) {
	profil_(&numnp, &nmat, x, matnum, &xsurf, beta, ah, ak, ath, thr, ths,
		 consat, hsat, &lscreen, &err);
	if (err == 1) {
	    goto L923;
	}
	nodout_(&numnp, &nmat, hnew, thold, con, x, &xsurf, &cosalf, &tinit, 
		matnum, cap, ak, sink, consat, &ns, &c__11, conc, tempo, sorb,
		 kappa, &lbact, sorb2, &lvapor, &lwtdep, conlt, convt, convh, 
		&thold[numnp - 1], &dt, &idualpor, thnewim, sinkim, strans, &
		ldensity, &lcentrif, &radius, &lvaporout, &ldualneq, &err);
	if (err == 1) {
	    goto L920;
	}
    }
    d__1 = t - dt;
    subreg_(&numnp, &nmat, &nlay, hnew, thold, thold, x, matnum, laynum, &
	    d__1, &dt, &cosalf, con, &lchem, conc, chpar, &c__0, ths, &wcumt, 
	    &wcuma, ccumt, ccuma, &wvoli, cvoli, watin, solin, &lwat, &ltemp, 
	    tempn, tpar, tdep, &ns, &c__11, sorb, llinear, &lequil, lmobim, &
	    err, subvol, area, &lprint, &lbact, sorb2, &lvapor, thvold, 
	    thvnew, &lwtdep, conlt, convh, convt, &idualpor, thnewim, tholdim,
	     &ldensity, &lcentrif, &radius, &ldualneq, cprevo);
    if (err == 1) {
	goto L921;
    }
    if (lchem || ltemp || lflux) {
	veloc_(&numnp, hold, con, x, &cosalf, vold, thold, thold, sink, &dt, &
		lvapor, &lwtdep, conlt, convt, convh, tempo, vvold, thvold, 
		thvold, &ldensity, conc, &c__11, &lcentrif, &radius);
    }
    i__1 = numnp;
    for (i__ = 1; i__ <= i__1; ++i__) {
	vnew[i__ - 1] = vold[i__ - 1];
	thnew[i__ - 1] = thold[i__ - 1];
	if (lvapor) {
	    thvnew[i__ - 1] = thvold[i__ - 1];
	}
	if (lvapor) {
	    vvnew[i__ - 1] = vvold[i__ - 1];
	}
/* L11: */
    }
    if (lbact && ! lwat) {
	exclusion_(&numnp, &nmat, &c__11, pard, chpar, thnew, vnew, thold, 
		vold);
    }
    if (lscreen) {
	s_wsle(&io___362);
	do_lio(&c__9, &c__1, "beginning of numerical solution", (ftnlen)31);
	e_wsle();
    }
/* using keyword arguments */
/* ---- START gettim and getdat gnu alternative function ---- */
    date_and_time__(date, time, zone, dtv, (ftnlen)8, (ftnlen)10, (ftnlen)5);
    hundred = 100;
    iyear = (shortint) dtv[0];
    imonth = (shortint) dtv[1];
    iday = (shortint) dtv[2];
    ihours = (shortint) dtv[4];
    imins = (shortint) dtv[5];
    isecs = (shortint) dtv[6];
    i100th = (shortint) (dtv[7] % hundred);
/*      call getdat(iYear,iMonth,iDay) */
/*      call gettim(iHours,iMins,iSecs,i100th) */
/* ---- END gettim and getdat gnu alternative function ---- */
    rtime1 = rtime_(&imonth, &iday, &ihours, &imins, &isecs, &i100th);
/*     Time stepping calculations --------------------------------------- */
L12:
/*     Loop between water flow and heat and vapor transport */
    itemp = 0;
L13:
    if (lenbal) {
	epsit = .5f;
	temps = epsit * tempn[numnp - 1] + (1.f - epsit) * tempo[numnp - 1];
	evapor_(&t, &temps, &tmaxa, &tmina, &rad, &hnew[numnp - 1], &
		tempheight, &windheight, &wind, &rhmean, &heatfl, &rtop, &
		prec, &tperiod, &rlat, &albedo, &sunhours, &thnew[numnp - 1], 
		&xconv, &tconv, &iradiation, &rns, &rnl, &rn, &sensflux, &
		evap, &xlat, &const__, &isunsh, &r_h__, &lmetdaily, &rst, &
		tempa, &rh_a__, &shwrada, &shwradb, &rlwrada, &rlwradb, &
		imethour);
    }
/*     Solve water movement --------------------------------------------- */
    if (lwat) {
	itcumo = itcum;
	watflow_(&numnp, ntab, &c__100, &nmat, htab, contab, captab, hnew, 
		hold, matnum, pard, parw, con, cap, consat, ah, ak, ath, hsat,
		 htemp, &kodtop, &kodbot, &rtop, &rbot, &cosalf, &t, &dt, x, 
		sink, p, r__, s, &freed, &seepf, &qgwlf, &aqh, &bqh, &gwl0l, &
		htop, &hbot, &hcrita, &hcrits, &wlayer, &iterw, &itcum, &
		topinf, &ktold, &kbold, &tolth, &tolh, &maxit, &dtmin, &told, 
		&dtopt, &convgf, thetab, thnew, thold, thr, ths, &lwtdep, 
		tempn, kappa, kappao, aths, thrr, cono, conr, aks, ahw, athw, 
		akw, &ihyst, &imodel, &qdrain, &zbotdr, &basegw, &rspacing, &
		iposdr, &rkhtop, &rkhbot, &rkvtop, &rkvbot, &entres, &wetper, 
		&zintf, &geofac, &ltable, &lvapor, &xconv, &tconv, conlt, 
		convt, convh, &tauw, theq, thvnew, thvold, &ntabmod, &
		idualpor, thnewim, tholdim, sinkim, &vtop, tempo, &itemp, &
		wtransf, &ldensity, conc, &c__11, &ienhanc, &lcentrif, &
		radius, &hseep);
	if (! convgf) {
	    ++inonconv;
	} else {
	    inonconv = 0;
	}
	if (lstopconv && ! convgf && inonconv >= 10) {
	    closeoutput_(&rtime1, &ns, &topinf, &botinf, &lchem, &lscreen, &
		    lmeteo, &lprint);
	    if (lenter) {
		s_wsle(&io___393);
		do_lio(&c__9, &c__1, "Press Enter to continue", (ftnlen)23);
		e_wsle();
		s_rsle(&io___394);
		e_rsle();
	    }
	    s_stop("", (ftnlen)0);
	}
	if (lmeteo && lmetdaily && ! lenbal) {
	    daymeteoout_(&t, &etcomb, &evapp, &transp, &rns, &rnl, &radterm, &
		    aeroterm, &precc, &rinterc, &excesint, &tempa, &rh_a__, &
		    rst, &lprint);
	}
/* Output for daily vari */
	if (lenbal) {
	    if (itcum > itcumo + maxit && ! lmetdaily) {
		meteoint_(&c__3, &t, &tatm2o, &tatm2, &rad, &rado, &radn, &
			tmaxa, &tmaxao, &tmaxan, &tmina, &tminao, &tminan, &
			wind, &windo, &windn, &rhmean, &rhmeano, &rhmeann, &
			sunhours, &sunhourso, &sunhoursn, &lenbal);
	    }
	    temps = epsit * tempn[numnp - 1] + (1.f - epsit) * tempo[numnp - 
		    1];
	    m = matnum[numnp - 1];
/* Computing MAX */
	    r__1 = 0.f, r__2 = tpar[m * 10 - 7] + tpar[m * 10 - 6] * thnew[
		    numnp - 1] + tpar[m * 10 - 5] * sqrt(thnew[numnp - 1]);
	    rlamb = dmax(r__1,r__2);
	    dz = x[numnp - 1] - x[numnp - 2];
	    updateenergy_(&t, &vtop, &rtop, &heatfl, &temps, &rns, &rnl, &rn, 
		    &evap, &xlat, &sensflux, &xconv, &tconv, &const__, &
		    tlevel, &nprstep, &r_h__, &dz, &rlamb, &itemp, &lprint, &
		    lmetdaily, &tempa, &rh_a__, &rst);
	}
    } else {
	iterw = 1;
	++itcum;
    }
/*     To calculate the velocities -------------------------------------- */
    if (lwat && (ltemp || lchem || lflux)) {
	veloc_(&numnp, hnew, con, x, &cosalf, vnew, thnew, thold, sink, &dt, &
		lvapor, &lwtdep, conlt, convt, convh, tempn, vvnew, thvnew, 
		thvold, &ldensity, conc, &c__11, &lcentrif, &radius);
    }
/*     Root zone calculations */
    if (lroot || icrop > 1) {
	setrg_(&numnp, x, beta, &t, &trmin, &trharv, &xrmin, &xrmax, &rgr, &
		xroot, &lroot, &irootin, &ngrowth, rgrowth, &trperiod);
    }
    if (sinkf) {
	setsnk_(&numnp, &nmat, matnum, x, &hroot, &vroot, sink, &rroot, hnew, 
		&lmosink, &lsolred, &lsoladd, &p0, poptm, &p2h, &p2l, &p3, &
		r2h, &r2l, aosm, &c50, &p3c, beta, &lchem, &ns, &c__11, conc, 
		croot, &lmssink, thnew, pard, &dt, &omegac, &imodel, con, &
		lomegaw, &omegaw, &rbot);
    }
/*     Calculation of heat transport ------------------------------------ */
    if (ltemp) {
	temper_(&numnp, &nmat, x, &dt, &t, matnum, tempo, tempn, tpar, &ampl, 
		p, r__, s, q, vold, vnew, thold, thnew, retard, disp, sink, &
		tperiod, &ktopt, &ttop, &kbott, &tbot, &lvapor, thvold, 
		thvnew, vvold, vvnew, g0, &lenbal, &heatfl, &xconv, &tconv, &
		dtmaxt, &icampbell, &itemp);
	if ((lvapor || lenbal) && itemp < 1) {
	    ++itemp;
	    goto L13;
	}
    }
/*     Calculations of the solute transport ----------------------------- */
    if (lchem) {
	ikod = 0;
	if (lflux) {
	    ikod = 2;
	}
	solute_(&numnp, &nmat, &ns, &c__11, x, &dt, &t, &tpulse, chpar, 
		matnum, thold, thnew, vold, vnew, disp, &epsi, &ktopch, ctop, 
		&kbotch, cbot, conc, p, r__, s, q, g0, g1, retard, cvtop, 
		cvbot, cvch0, cvch1, &lupw, wc, &peclet, &courant, &dtmaxc, 
		tempo, tempn, cnew, cprevo, ctemp, tdep, ths, &ctola, &ctolr, 
		&iterc, &maxitc, htemp, sorb, sorbn, llinear, &lequil, &lartd,
		 &pecr, q0, q1, &dsurf, &catm, &ltort, sink, crootmax, ssink, 
		cvchr, lmobim, cvchim, &tlevel, &lbact, sorb2, sorbn2, &dtmin,
		 &dtopt, &lwat, &lfiltr, &idualpor, tholdim, thnewim, sinkim, 
		strans, &itort, &xconv, &tconv, &lvapor, &rbot, &err, &
		imoistdep, &c__20, dmoist, wdep, &ikod, beta, &ldualneq, &
		atmbc, &sinkf, &lactrsu, &omegas, &omegaw, &spot, &rkm, &cmin,
		 &ldensity);
	if (err != 0) {
	    goto L927;
	}
    }
/*     Output ------------------------------------------------------------ */
/*     T-level information */
    if ((d__1 = t - tmax, abs(d__1)) <= dtmin * .5f || t > tmax) {
	lend = TRUE_;
    }
    jprint = 0;
    if ((d__1 = tprint[plevel - 1] - t, abs(d__1)) < dt * .001f || lprintd && 
	    (d__2 = tprint1 - t, abs(d__2)) < dt * .001f || ! shorto && (r__1 
	    = (real) ((tlevel + nprstep - 1) / nprstep) - (tlevel + nprstep - 
	    1) / (real) nprstep, dabs(r__1)) < 1e-4f) {
	jprint = 1;
    }
    tlinf_(&numnp, con, x, &cosalf, &t, &dt, &iterw, &iterc, &tlevel, &rtop, &
	    rroot, &vroot, hnew, &hroot, cumq, &itcum, &kodtop, &kodbot, &
	    convgf, &lwat, &lchem, croot, &ns, &c__11, conc, cvtop, cvbot, 
	    cvch0, cvch1, &peclet, &courant, &wcumt, &wcuma, ccumt, ccuma, 
	    cumch, thnew, thold, sink, &lscreen, &err, cvchr, cvchim, &lprint,
	     &lvapor, &lwtdep, conlt, convh, convt, tempn, &rsoil, &prec, &
	    nprstep, thvold, thvnew, &xconv, &idualpor, sinkim, &wtransf, &
	    ldensity, &snowlayer, &lcentrif, &radius, thnewim, &wlayer, &
	    hcrits, &lend, &lfluxout, &jprint, &dummy1, &dummy2, &lflux, &
	    nobs, node, vnew, cnew, ctop);
    if (err != 0) {
	switch (err) {
	    case 1:  goto L919;
	    case 2:  goto L918;
	    case 3:  goto L926;
	}
    }
    if (nobs > 0 && lprint && jprint == 1) {
	obsnod_(&t, &numnp, &nobs, &ns, &c__11, node, conc, hnew, thnew, 
		tempn, &lchem, thnewim, vnew, vvnew, &lflux, &err);
	if (err == 1) {
	    goto L922;
	}
    }
    if (lprintd && (d__1 = tprint1 - t, abs(d__1)) < dt * .001f) {
	tprint1 += tprintint;
    }
/*     P-level information ---------------------------------------------- */
    if ((d__1 = tprint[plevel - 1] - t, abs(d__1)) < dt * .001f) {
	if (lprint) {
	    nodout_(&numnp, &nmat, hnew, thnew, con, x, &xsurf, &cosalf, &
		    tprint[plevel - 1], matnum, cap, ak, sink, consat, &ns, &
		    c__11, conc, tempn, sorb, kappa, &lbact, sorb2, &lvapor, &
		    lwtdep, conlt, convt, convh, &thold[numnp - 1], &dt, &
		    idualpor, thnewim, sinkim, strans, &ldensity, &lcentrif, &
		    radius, &lvaporout, &ldualneq, &err);
	    if (err == 1) {
		goto L920;
	    }
	}
	subreg_(&numnp, &nmat, &nlay, hnew, thnew, thold, x, matnum, laynum, &
		t, &dt, &cosalf, con, &lchem, conc, chpar, &plevel, ths, &
		wcumt, &wcuma, ccumt, ccuma, &wvoli, cvoli, watin, solin, &
		lwat, &ltemp, tempn, tpar, tdep, &ns, &c__11, sorb, llinear, &
		lequil, lmobim, &err, subvol, area, &lprint, &lbact, sorb2, &
		lvapor, thvold, thvnew, &lwtdep, conlt, convh, convt, &
		idualpor, thnewim, tholdim, &ldensity, &lcentrif, &radius, &
		ldualneq, cprevo);
	if (err == 1) {
	    goto L921;
	}
	++plevel;
    }
/*     A-level information ---------------------------------------------- */
    if ((d__1 = t - tatm, abs(d__1)) <= dt * .001f && (topinf || botinf || 
	    atmbc)) {
	if (lprint) {
	    alinf_(&t, cumq, &hnew[numnp - 1], &hroot, hnew, &alevel, &err);
	    if (err != 0) {
		switch (err) {
		    case 1:  goto L925;
		}
	    }
	}
	if ((d__1 = t - tatm1, abs(d__1)) <= dt * .001f) {
	    tatmold = tatm1;
	    setbc_(&tmax, &tatm1, &rtop, &rr, &rbot, &hcrita, &hbot, &htop, &
		    gwl0l, &topinf, &botinf, ct, cbot, &ns, &ttop, &tbot, &
		    ampl, &ltemp, &lchem, &kodtop, &lvarbc, &err, &lminstep, &
		    lmeteo, &prec, &rs, &llai, &rextinct, &lcentrif, &cosalf, 
		    &xconv, &tconv, &imodel, &hnew[numnp - 1], &irootin, &
		    xroot, &wlayer, llinear, &lactrsu, &spot);
	    if (err == 1) {
		goto L913;
	    }
	    if (! lmeteo) {
		rroot = rr;
		rsoil = rs;
	    }
	}
	if (lmeteo && (d__1 = t - tatm2, abs(d__1)) <= dt * .001f) {
	    meteo_(&c__2, &lmetdaily, &ldayvar, &t, &dt, &tinit, &tmax, &
		    tatm2, &tatmn, &tatm2o, &dtmax, &rlat, &ralt, &shwrada, &
		    shwradb, &rlwrada, &rlwradb, &rlwrada1, &rlwradb1, &
		    windheight, &tempheight, &icrop, &ilai, &rroot, &xconv, &
		    tconv, rgrowth, &ngrowth, &iinterc, &rinterc, &ainterc, &
		    excesint, &lenbal, &rextinct, &lprint, &lhargr, &
		    iradiation, &isunsh, &irelhum, &imethour, &cloudf_ac__, &
		    cloudf_bc__, &prec, &precc, &rsoil, &evapp, &transp, &rns,
		     &rnl, &radterm, &aeroterm, &rst, &etcomb, &rad, &radn, &
		    rado, &wind, &windn, &windo, &albedo, &albedon, &xlai, &
		    xlain, &xroot, &xrootn, &cropheight, &cropheightn, &ampl, 
		    &ttop, &tmaxan, &tminan, &tmax1, &tmaxn, &tmaxo, &tmin1, &
		    tminn, &tmino, &tempa, &tmaxa, &tmaxao, &tmina, &tminao, &
		    sunhours, &sunhoursn, &sunhourso, &rhmean, &rhmeann, &
		    rhmeano, &rhmax, &rhmaxn, &rhmaxo, &rhmin, &rhminn, &
		    rhmino, &rh_a__, &eamean, &eameann, &rtop, &err);
	    if (err != 0) {
		switch (err) {
		    case 1:  goto L932;
		    case 2:  goto L913;
		    case 3:  goto L933;
		}
	    }
	}
	tatm = min(tatm1,tatm2);
	if (lchem && snowlayer <= 0.f) {
	    setchembc_(&prec, &rsoil, &ns, ctop, ct, &wlayer, &hnew[numnp - 1]
		    , &kodtop, &ktopch);
	}
	if (lsnow) {
	    dtsnow = (real) (tatm1 - tatmold);
	    snow_(&prec, &dtsnow, &ttop, &snowmf, &snowlayer, &rsoil, &xconv, 
		    &lminstep, ctop, ct, &ns);
	}
	if (ldayvar) {
	    rrootd = rroot;
	    rsoild = rsoil;
	}
	if (lsinprec) {
	    precd = prec;
	}
	if (! lvarbc && kodtop == -4) {
	    rtop = dabs(rsoil) - dabs(prec);
	}
	if (! lvarbc) {
	    rtop = dabs(rsoil) - dabs(prec);
	}
	++alevel;
    }
    if (wlayer && hnew[numnp - 1] > 0.f) {
/* mass balance in the surfac */
	ht = hnew[numnp - 1];
	i__1 = ns;
	for (jj = 1; jj <= i__1; ++jj) {
	    if (ht + dt * (prec - rsoil) > 0.f) {
		ctop[jj - 1] = (ht * ctop[jj - 1] + dt * prec * ct[jj - 1]) / 
			(ht + dt * (prec - rsoil));
	    }
/* L15: */
	}
    }
/*     Time governing --------------------------------------------------- */
    if ((d__1 = t - tmax, abs(d__1)) <= dtmin * .5f || t > tmax) {
	closeoutput_(&rtime1, &ns, &topinf, &botinf, &lchem, &lscreen, &
		lmeteo, &lprint);
	if (lenter) {
	    s_wsle(&io___425);
	    do_lio(&c__9, &c__1, "Press Enter to continue", (ftnlen)23);
	    e_wsle();
	    s_rsle(&io___426);
	    e_rsle();
	}
	s_stop("", (ftnlen)0);
    } else {
	told = t;
	dtold = dt;
	ktold = kodtop;
	kbold = kodbot;
	if (! lwat) {
	    iterw = 1;
	}
	iter = max(iterw,iterc);
	dtmaxa = dmin(dtmaxc,dtmaxt);
	if (lsinprec && precd > 0.f) {
/* Computing MIN */
	    r__1 = dtmaxa, r__2 = (real) (tatm1 - tatmold) / 20.f;
	    dtmaxa = dmin(r__1,r__2);
	}
/* Computing MIN */
	d__2 = tprint[plevel - 1];
	d__1 = min(d__2,tprint1);
	tmcont_(&dt, &dtmax, &dtopt, &dmul, &dmul2, &dtmin, &iter, &d__1, &
		tatm, &t, &tmax, &dtmaxa, &itmin, &itmax, &lminstep, &dtinit);
	t += dt;
	if (ldayvar) {
	    dailyvar_(&tconv, &t, &rroot, &rrootd);
	    dailyvar_(&tconv, &t, &rsoil, &rsoild);
	    rtop = dabs(rsoil) - dabs(prec);
	}
	if (lsinprec) {
	    sinprec_(&t, &tatmold, &tatm1, &prec, &precd);
	    rtop = dabs(rsoil) - dabs(prec);
	}
	if (lmeteo) {
	    meteo_(&c__3, &lmetdaily, &ldayvar, &t, &dt, &tinit, &tmax, &
		    tatm2, &tatmn, &tatm2o, &dtmax, &rlat, &ralt, &shwrada, &
		    shwradb, &rlwrada, &rlwradb, &rlwrada1, &rlwradb1, &
		    windheight, &tempheight, &icrop, &ilai, &rroot, &xconv, &
		    tconv, rgrowth, &ngrowth, &iinterc, &rinterc, &ainterc, &
		    excesint, &lenbal, &rextinct, &lprint, &lhargr, &
		    iradiation, &isunsh, &irelhum, &imethour, &cloudf_ac__, &
		    cloudf_bc__, &prec, &precc, &rsoil, &evapp, &transp, &rns,
		     &rnl, &radterm, &aeroterm, &rst, &etcomb, &rad, &radn, &
		    rado, &wind, &windn, &windo, &albedo, &albedon, &xlai, &
		    xlain, &xroot, &xrootn, &cropheight, &cropheightn, &ampl, 
		    &ttop, &tmaxan, &tminan, &tmax1, &tmaxn, &tmaxo, &tmin1, &
		    tminn, &tmino, &tempa, &tmaxa, &tmaxao, &tmina, &tminao, &
		    sunhours, &sunhoursn, &sunhourso, &rhmean, &rhmeann, &
		    rhmeano, &rhmax, &rhmaxn, &rhmaxo, &rhmin, &rhminn, &
		    rhmino, &rh_a__, &eamean, &eameann, &rtop, &err);
	    if (err != 0) {
		switch (err) {
		    case 1:  goto L932;
		    case 2:  goto L913;
		    case 3:  goto L933;
		}
	    }
	}
	++tlevel;
	if (tlevel > 1000000) {
	    tlevel = 2;
	}
    }
/*     New updated values */
    update_(&numnp, &lwat, &lchem, &ltemp, &lvapor, &idualpor, &lextrap, &dt, 
	    &dtold, htemp, hnew, hold, thold, thnew, vold, vnew, thvold, 
	    thvnew, vvold, vvnew, tholdim, thnewim, tempo, tempn, &rtop, &
	    xconv, &consmax, &kodtop, &kodbot);
    goto L12;
/* --- End of time loop ------------------------------------------------- */
/*     Error messages */
L901:
    ierr = 1;
    goto L1000;
L902:
    ierr = 2;
    goto L1000;
L903:
    ierr = 3;
    goto L1000;
L904:
    ierr = 4;
    goto L1000;
L905:
    ierr = 5;
    goto L1000;
L906:
    ierr = 6;
    goto L1000;
L907:
    ierr = 7;
    goto L1000;
L908:
    ierr = 8;
    goto L1000;
L909:
    ierr = 9;
    goto L1000;
L910:
    ierr = 10;
    goto L1000;
L911:
    ierr = 11;
    goto L1000;
L912:
    ierr = 12;
    goto L1000;
L913:
    ierr = 13;
    goto L1000;
L914:
    ierr = 14;
    goto L1000;
L915:
    ierr = 15;
    goto L1000;
L916:
    ierr = 16;
    goto L1000;
/* 917   ierr=17 */
/*      goto 1000 */
L918:
    ierr = 18;
    goto L1000;
L919:
    ierr = 19;
    goto L1000;
L920:
    ierr = 20;
    goto L1000;
L921:
    ierr = 21;
    goto L1000;
L922:
    ierr = 22;
    goto L1000;
L923:
    ierr = 23;
    goto L1000;
L924:
    ierr = 24;
    goto L1000;
L925:
    ierr = 25;
    goto L1000;
L926:
    ierr = 26;
    goto L1000;
L927:
    ierr = 27;
    goto L1000;
L928:
    ierr = 28;
    goto L1000;
L929:
    ierr = 29;
    goto L1000;
L930:
    ierr = 30;
    goto L1000;
L931:
    ierr = 31;
    goto L1000;
L932:
    ierr = 32;
    goto L1000;
L933:
    ierr = 33;
    goto L1000;
L1000:
    errorout_(&ierr, cfilename, cdatapath, &ilengthpath, &lscreen, (ftnlen)
	    260, (ftnlen)260);
    if (lenter) {
	s_wsle(&io___430);
	do_lio(&c__9, &c__1, "Press Enter to continue", (ftnlen)23);
	e_wsle();
	s_rsle(&io___431);
	e_rsle();
    }
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

/* *********************************************************************** */
/* Subroutine */ int errorout_(integer *ierr, char *cfilename, char *
	cdatapath, integer *ilengthpath, logical *lscreen, ftnlen 
	cfilename_len, ftnlen cdatapath_len)
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2;
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer f_open(olist *), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle(void), f_clos(cllist *);

    /* Local variables */
    static char cerr__[260*33], cfilenameerr[260];

    /* Fortran I/O blocks */
    static cilist io___434 = { 0, 6, 0, 0, 0 };
    static cilist io___435 = { 0, 99, 0, 0, 0 };
    static cilist io___436 = { 0, 6, 0, 0, 0 };
    static cilist io___437 = { 0, 99, 0, 0, 0 };
    static cilist io___438 = { 0, 6, 0, 0, 0 };
    static cilist io___439 = { 0, 6, 0, 0, 0 };


    s_copy(cerr__, "Open file error in file :", (ftnlen)260, (ftnlen)25);
    s_copy(cerr__ + 260, "File already exists or hard disk is full ! Open fi"
	    "le error in output file : ", (ftnlen)260, (ftnlen)76);
    s_copy(cerr__ + 520, "Error when writing to an output file !", (ftnlen)
	    260, (ftnlen)38);
    s_copy(cerr__ + 780, "Error when reading from an input file Level_01.dir"
	    " data\rpathway !", (ftnlen)260, (ftnlen)65);
    s_copy(cerr__ + 1040, "Error when reading from an input file Selector.in"
	    " Basic\rInformations !", (ftnlen)260, (ftnlen)70);
    s_copy(cerr__ + 1300, "Error when reading from an input file Selector.in"
	    " Water\rFlow Informations !", (ftnlen)260, (ftnlen)75);
    s_copy(cerr__ + 1560, "Error when reading from an input file Selector.in"
	    " Time Informations !", (ftnlen)260, (ftnlen)69);
    s_copy(cerr__ + 1820, "Error when reading from an input file Selector.in"
	    " Root Growth Informations !", (ftnlen)260, (ftnlen)76);
    s_copy(cerr__ + 2080, "Error when reading from an input file Selector.in"
	    " Sink Informations !", (ftnlen)260, (ftnlen)69);
    s_copy(cerr__ + 2340, "Error when reading from an input file Selector.in"
	    " Heat Transport Informations !", (ftnlen)260, (ftnlen)79);
    s_copy(cerr__ + 2600, "Error when reading from an input file Selector.in"
	    " Solute Transport Informations !", (ftnlen)260, (ftnlen)81);
    s_copy(cerr__ + 2860, "Error when reading from an input file Profile.dat"
	    " !", (ftnlen)260, (ftnlen)51);
    s_copy(cerr__ + 3120, "Error when reading from an input file Atmosph.in !"
	    , (ftnlen)260, (ftnlen)50);
    s_copy(cerr__ + 3380, "Dimension in NumNPD is exceeded !", (ftnlen)260, (
	    ftnlen)33);
    s_copy(cerr__ + 3640, "Dimension in NObsD is exceeded !", (ftnlen)260, (
	    ftnlen)32);
    s_copy(cerr__ + 3900, "Dimension in NMatD or NLay is exceeded !", (ftnlen)
	    260, (ftnlen)40);
    s_copy(cerr__ + 4160, "Error when writing into an output file I_CHECK.OU"
	    "T !", (ftnlen)260, (ftnlen)52);
    s_copy(cerr__ + 4420, "Error when writing into an output file RUN_INF.OU"
	    "T !", (ftnlen)260, (ftnlen)52);
    s_copy(cerr__ + 4680, "Error when writing into an output file T_LEVEL.OU"
	    "T !", (ftnlen)260, (ftnlen)52);
    s_copy(cerr__ + 4940, "Error when writing into an output file NOD_INF.OU"
	    "T !", (ftnlen)260, (ftnlen)52);
    s_copy(cerr__ + 5200, "Error when writing into an output file BALANCE.OU"
	    "T !", (ftnlen)260, (ftnlen)52);
    s_copy(cerr__ + 5460, "Error when writing into an output file OBS_NODE.O"
	    "UT !", (ftnlen)260, (ftnlen)53);
    s_copy(cerr__ + 5720, "Error when writing into an output file PROFILE.OU"
	    "T !", (ftnlen)260, (ftnlen)52);
    s_copy(cerr__ + 5980, "Initial water content condition is lower than Qr !"
	    , (ftnlen)260, (ftnlen)50);
    s_copy(cerr__ + 6240, "Error when writing into an output file A_LEVEL.OU"
	    "T !", (ftnlen)260, (ftnlen)52);
    s_copy(cerr__ + 6500, "Error when writing into an output file SOLUTE.OUT"
	    " !", (ftnlen)260, (ftnlen)51);
    s_copy(cerr__ + 6760, "Does not converge in the solute transport module !"
	    , (ftnlen)260, (ftnlen)50);
    s_copy(cerr__ + 7020, "Number of Print-Times is exceeded !", (ftnlen)260, 
	    (ftnlen)35);
    s_copy(cerr__ + 7280, "Dimension in NSD is exceeded !", (ftnlen)260, (
	    ftnlen)30);
    s_copy(cerr__ + 7540, "The path to the project is too long !!!", (ftnlen)
	    260, (ftnlen)39);
    s_copy(cerr__ + 7800, "Bulk density can not be equal to zero !", (ftnlen)
	    260, (ftnlen)39);
    s_copy(cerr__ + 8060, "Error when reading from an input file Meteo.in !", 
	    (ftnlen)260, (ftnlen)48);
    s_copy(cerr__ + 8320, "Crop Height must be smaller than the height of wi"
	    "nd and temperature measurements!", (ftnlen)260, (ftnlen)81);
/* Writing concatenation */
    i__1[0] = *ilengthpath, a__1[0] = cdatapath;
    i__1[1] = 10, a__1[1] = "/Error.msg";
    s_cat(cfilenameerr, a__1, i__1, &c__2, (ftnlen)260);
    o__1.oerr = 1;
    o__1.ounit = 99;
    o__1.ofnmlen = 260;
    o__1.ofnm = cfilenameerr;
    o__1.orl = 0;
    o__1.osta = "unknown";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__2 = f_open(&o__1);
    if (i__2 != 0) {
	goto L901;
    }
    if (*ierr <= 2) {
	if (*lscreen) {
	    s_wsle(&io___434);
	    do_lio(&c__9, &c__1, cerr__ + (*ierr - 1) * 260, (ftnlen)260);
	    do_lio(&c__9, &c__1, cfilename, (ftnlen)260);
	    e_wsle();
	}
	s_wsle(&io___435);
	do_lio(&c__9, &c__1, cerr__ + (*ierr - 1) * 260, (ftnlen)260);
	do_lio(&c__9, &c__1, cfilename, (ftnlen)260);
	e_wsle();
    } else {
	if (*lscreen) {
	    s_wsle(&io___436);
	    do_lio(&c__9, &c__1, cerr__ + (*ierr - 1) * 260, (ftnlen)260);
	    e_wsle();
	}
	s_wsle(&io___437);
	do_lio(&c__9, &c__1, cerr__ + (*ierr - 1) * 260, (ftnlen)260);
	e_wsle();
    }
    cl__1.cerr = 0;
    cl__1.cunit = 99;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
L901:
    s_wsle(&io___438);
    do_lio(&c__9, &c__1, "Folder with input data of the specified project do"
	    "es not exist or pathway is too long or corrupted", (ftnlen)98);
    e_wsle();
    s_wsle(&io___439);
    do_lio(&c__9, &c__1, cfilename, (ftnlen)260);
    e_wsle();
    return 0;
} /* errorout_ */

/* *********************************************************************** */
/* Subroutine */ int closeoutput_(doublereal *rtime1, integer *ns, logical *
	topinf, logical *botinf, logical *lchem, logical *lscreen, logical *
	lmeteo, logical *lprint)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer jj, dtv[8];
    static char date[8];
    static shortint iday;
    static char time[10], zone[5];
    static shortint i100th, isecs, iyear;
    extern /* Subroutine */ int date_and_time__(char *, char *, char *, 
	    integer *, ftnlen, ftnlen, ftnlen);
    static shortint imins;
    extern doublereal rtime_(shortint *, shortint *, shortint *, shortint *, 
	    shortint *, shortint *);
    static doublereal rtime2;
    static shortint imonth, ihours;
    static integer hundred;

    /* Fortran I/O blocks */
    static cilist io___453 = { 0, 6, 0, 0, 0 };
    static cilist io___454 = { 0, 70, 0, "('end')", 0 };
    static cilist io___455 = { 0, 76, 0, 0, 0 };
    static cilist io___456 = { 0, 76, 0, 0, 0 };
    static cilist io___457 = { 0, 71, 0, "('end')", 0 };
    static cilist io___458 = { 0, 72, 0, "('end')", 0 };
    static cilist io___459 = { 0, 43, 0, "('end')", 0 };
    static cilist io___460 = { 0, 77, 0, "('end')", 0 };
    static cilist io___462 = { 0, 0, 0, "('end')", 0 };


/*      use MSFLIB */
/* ---- START gettim and getdat gnu alternative function ---- */
    date_and_time__(date, time, zone, dtv, (ftnlen)8, (ftnlen)10, (ftnlen)5);
    hundred = 100;
    iyear = (shortint) dtv[0];
    imonth = (shortint) dtv[1];
    iday = (shortint) dtv[2];
    ihours = (shortint) dtv[4];
    imins = (shortint) dtv[5];
    isecs = (shortint) dtv[6];
    i100th = (shortint) (dtv[7] % hundred);
/*      call getdat(iYear,iMonth,iDay) */
/*      call gettim(iHours,iMins,iSecs,i100th) */
/* ---- END gettim and getdat gnu alternative function ---- */
    rtime2 = rtime_(&imonth, &iday, &ihours, &imins, &isecs, &i100th);
    if (*lscreen) {
	s_wsle(&io___453);
	do_lio(&c__9, &c__1, "Real time [sec]", (ftnlen)15);
	d__1 = rtime2 - *rtime1;
	do_lio(&c__5, &c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsle();
    }
    if (*lprint) {
	s_wsfe(&io___454);
	e_wsfe();
	s_wsle(&io___455);
	e_wsle();
	s_wsle(&io___456);
	do_lio(&c__9, &c__1, "Calculation time [sec]", (ftnlen)22);
	d__1 = rtime2 - *rtime1;
	do_lio(&c__5, &c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsle();
	s_wsfe(&io___457);
	e_wsfe();
	if (*topinf || *botinf) {
	    s_wsfe(&io___458);
	    e_wsfe();
	    if (*lmeteo) {
		s_wsfe(&io___459);
		e_wsfe();
	    }
	}
	s_wsfe(&io___460);
	e_wsfe();
	if (*lchem) {
	    i__1 = *ns;
	    for (jj = 1; jj <= i__1; ++jj) {
		io___462.ciunit = jj + 80;
		s_wsfe(&io___462);
		e_wsfe();
/* L13: */
	    }
	}
    }
    return 0;
} /* closeoutput_ */

/* |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| */
/* ----------------------------------------------------------------------- */
/*     Signal handler routines */
/* ----------------------------------------------------------------------- */
/*      integer(4) function h_sig (signum) */
/*        use MSFLIB */
/*        !MS$ATTRIBUTES C :: h_sig */
/*        integer(2) signum */
/*        select case (signum) */
/*          case (SIG$ABORT) */
/*            write(*,*) 'Abnormal termination !' */
/*          case (SIG$INT) */
/*            write(*,*) 'Program terminated !' */
/*          case (SIG$FPE) */
/*            write(*,*) 'Floating point error !' */
/*          case (SIG$BREAK) */
/*            write(*,*) 'Program terminated !' */
/*          case default */
/*            write(*,*) 'Unknown signal handler !' */
/*        end select */
/*        h_sig = 1 */
/*        call CloseFiles */
/*        stop */
/*      end */

/*      function hand_fpe (signum, excnum) */
/*        !MS$ATTRIBUTES C :: hand_fpe */
/*        use MSFLIB */
/*        integer(2)  signum, excnum */
/*        select case(excnum) */
/*          case(FPE$INVALID ) */
/*            write(*,*) 'Floating Point Error - Invalid number !' */
/*          case( FPE$DENORMAL ) */
/*            write(*,*) 'Floating Point Error - Denormalized number !' */
/*          case( FPE$ZERODIVIDE ) */
/*            write(*,*) 'Floating Point Error - Zero divide !' */
/*          case( FPE$OVERFLOW ) */
/*            write(*,*) 'Floating Point Error - Overflow !' */
/*          case( FPE$UNDERFLOW ) */
/*            write(*,*) 'Floating Point Error - Underflow !' */
/*          case( FPE$INEXACT ) */
/*            write(*,*) 'Floating Point Error - Inexact precision !' */
/*          case default */
/*            write(*,*) 'Floating Point Error - Non-IEEE type !' */
/*        end select */
/*        hand_fpe = 1 */
/*        call CloseFiles */
/*      end */

/* *********************************************************************** */
/* Subroutine */ int closefiles_(void)
{
    /* System generated locals */
    cllist cl__1;
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *), s_wsfe(cilist *), e_wsfe(void), f_clos(cllist *)
	    ;

    /* Local variables */
    static logical lopen;

    /* Fortran I/O blocks */
    static cilist io___464 = { 0, 43, 0, "('end')", 0 };
    static cilist io___465 = { 0, 44, 0, "('end')", 0 };
    static cilist io___466 = { 0, 70, 0, "('end')", 0 };
    static cilist io___467 = { 0, 71, 0, "('end')", 0 };
    static cilist io___468 = { 0, 72, 0, "('end')", 0 };
    static cilist io___469 = { 0, 77, 0, "('end')", 0 };
    static cilist io___470 = { 0, 81, 0, "('end')", 0 };
    static cilist io___471 = { 0, 82, 0, "('end')", 0 };
    static cilist io___472 = { 0, 83, 0, "('end')", 0 };


    ioin__1.inerr = 0;
    ioin__1.inunit = 43;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	s_wsfe(&io___464);
	e_wsfe();
	cl__1.cerr = 0;
	cl__1.cunit = 43;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 44;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	s_wsfe(&io___465);
	e_wsfe();
	cl__1.cerr = 0;
	cl__1.cunit = 44;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 70;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	s_wsfe(&io___466);
	e_wsfe();
	cl__1.cerr = 0;
	cl__1.cunit = 70;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 71;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	s_wsfe(&io___467);
	e_wsfe();
	cl__1.cerr = 0;
	cl__1.cunit = 71;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 72;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	s_wsfe(&io___468);
	e_wsfe();
	cl__1.cerr = 0;
	cl__1.cunit = 72;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 77;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	s_wsfe(&io___469);
	e_wsfe();
	cl__1.cerr = 0;
	cl__1.cunit = 77;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 75;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	cl__1.cerr = 0;
	cl__1.cunit = 75;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 76;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	cl__1.cerr = 0;
	cl__1.cunit = 76;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 78;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	cl__1.cerr = 0;
	cl__1.cunit = 78;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 31;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	cl__1.cerr = 0;
	cl__1.cunit = 31;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 81;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	s_wsfe(&io___470);
	e_wsfe();
	cl__1.cerr = 0;
	cl__1.cunit = 81;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 82;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	s_wsfe(&io___471);
	e_wsfe();
	cl__1.cerr = 0;
	cl__1.cunit = 82;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 83;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	s_wsfe(&io___472);
	e_wsfe();
	cl__1.cerr = 0;
	cl__1.cunit = 83;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 41;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	cl__1.cerr = 0;
	cl__1.cunit = 41;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    ioin__1.inerr = 0;
    ioin__1.inunit = 42;
    ioin__1.infile = 0;
    ioin__1.inex = 0;
    ioin__1.inopen = &lopen;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (lopen) {
	cl__1.cerr = 0;
	cl__1.cunit = 42;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    return 0;
} /* closefiles_ */

/* Main program alias */ int hydrus_ () { MAIN__ (); return 0; }
