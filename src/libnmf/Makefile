#################################################################################
#--------------------------------Makefile---------------------------------------#
#									   	#
#	NMF Library							   	#
#									   	#
#	Note: 	All object files are created in the source folder		#
#		The libraries are created in the folder given by LIBFOLDER	#
#		Please make sure the folder in LIBFOLDER exists			#
#										#
#		For creating the shared library add '-fPIC' to GCCFLAGS		#
#									   	#
#	make lib	create libnnmf.a				   	#
#	make shared	create shared library libnnmf.so		   	#
#	make clean	delete library and object files			   	#
#									   	#
#									   	#
#									   	#
#################################################################################

#Variables

COMPILER='gcc'
LIBFOLDER='lib'
GCCFLAGS=-Wall -Wextra -Iinclude/ -O2 -fopenmp

# for creating the shared library use:
#GCCFLAGS=-fPIC -Wall -Wextra -Iinclude/


all: lib

lib:          checkarguments.o checkarguments_singleprec.o infogain_openmp.o infogain_openmp_singleprec.o infogain.o infogain_singleprec.o getentropy.o getentropy_singleprec.o getinfogainforattribute.o getinfogainforattribute_singleprec.o getattrvalvsclassoccurence.o getattrvalvsclassoccurence_singleprec.o cpmidx_double.o cpmidx_float.o  loadmatrix.o loadmatrix_singleprec.o  nmfdriver.o nmfdriver_singleprec.o nmf_pg.o  nmf_pg_singleprec.o  nmf_fast.o nmf_fast_singleprec.o  nmf_bayes.o  nmf_bayes_singleprec.o  randnumber.o randnumber_singleprec.o\
	calculatemaxchange.o calculatemaxchange_singleprec.o checkmatrices.o checkmatrices_singleprec.o  nmf_als.o nmf_als_singleprec.o    nmf_mu.o nmf_mu_singleprec.o    outputtiming.o  setdefaultopts.o setdefaultopts_singleprec.o \
	calculatenorm.o   calculatenorm_singleprec.o   generatematrix.o  generatematrix_singleprec.o  nmf_alspg.o nmf_alspg_singleprec.o  nmf_neals.o nmf_neals_singleprec.o  pg_subprob_h.o pg_subprob_h_singleprec.o  pg_subprob_w.o pg_subprob_w_singleprec.o  storematrix.o storematrix_singleprec.o\
	calculatesvd.o calculatesvd_singleprec.o
	ar rcs $(LIBFOLDER)/libnnmf.a   infogain_openmp.o infogain_openmp_singleprec.o   infogain.o infogain_singleprec.o getentropy.o getentropy_singleprec.o getinfogainforattribute.o getinfogainforattribute_singleprec.o getattrvalvsclassoccurence.o getattrvalvsclassoccurence_singleprec.o cpmidx_double.o   cpmidx_float.o   checkarguments.o checkarguments_singleprec.o     loadmatrix.o loadmatrix_singleprec.o nmfdriver.o nmfdriver_singleprec.o nmf_pg.o nmf_pg_singleprec.o nmf_fast.o  nmf_fast_singleprec.o nmf_bayes.o nmf_bayes_singleprec.o randnumber_singleprec.o\
	  randnumber.o calculatemaxchange.o  calculatemaxchange_singleprec.o checkmatrices.o checkmatrices_singleprec.o  nmf_als.o  nmf_als_singleprec.o   nmf_mu.o   nmf_mu_singleprec.o  outputtiming.o \
	  setdefaultopts.o setdefaultopts_singleprec.o calculatenorm.o  calculatenorm_singleprec.o  generatematrix.o generatematrix_singleprec.o nmf_alspg.o nmf_alspg_singleprec.o  nmf_neals.o nmf_neals_singleprec.o pg_subprob_h.o pg_subprob_h_singleprec.o pg_subprob_w.o pg_subprob_w_singleprec.o\
	  storematrix.o storematrix_singleprec.o calculatesvd.o calculatesvd_singleprec.o

shared: lib
	      $(COMPILER) -shared -Wl,-soname,libnnmf.so -o $(LIBFOLDER)/libnnmf.so  blaslapack.o infogain.o infogain_singleprec.o getentropy.o getentropy_singleprec.o getinfogainforattribute.o getinfogainforattribute_singleprec.o getattrvalvsclassoccurence.o getattrvalvsclassoccurence_singleprec.o checkarguments.o checkarguments_singleprec.o cpmidx_double.o cpmidx_float.o   loadmatrix.o loadmatrix_singleprec.o nmfdriver.o nmfdriver_singleprec.o nmf_pg.o  nmf_pg_singleprec.o nmf_fast.o nmf_fast_singleprec.o  nmf_bayes.o nmf_bayes_singleprec.o randnumber_singleprec.o\
		randnumber.o calculatemaxchange.o calculatemaxchange_singleprec.o checkmatrices.o checkmatrices_singleprec.o nmf_als.o  nmf_als_singleprec.o   nmf_mu.o   nmf_mu_singleprec.o  outputtiming.o \
		setdefaultopts.o setdefaultopts_singleprec.o calculatenorm.o  calculatenorm_singleprec.o     common.o  generatematrix.o  generatematrix_singleprec.o  nmf_alspg.o nmf_alspg_singleprec.o  nmf_neals.o nmf_neals_singleprec.o pg_subprob_h.o pg_subprob_h_singleprec.o pg_subprob_w.o pg_subprob_w_singleprec.o\
		storematrix.o storematrix_singleprec.o calculatesvd.o calculatesvd_singleprec.o



calculatesvd.o: calculatesvd.c include/calculatesvd.h
	      $(COMPILER) $(GCCFLAGS) -c calculatesvd.c -c

calculatesvd_singleprec.o: calculatesvd_singleprec.c include/calculatesvd_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c calculatesvd_singleprec.c -c

blaslapack.o: blaslapack.c include/blaslapack.h
	      $(COMPILER) $(GCCFLAGS) -c blaslapack.c -c 

checkarguments.o: checkarguments.c include/checkarguments.h
	      $(COMPILER) $(GCCFLAGS) -c checkarguments.c -c

checkarguments_singleprec.o: checkarguments_singleprec.c include/checkarguments_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c checkarguments_singleprec.c -c

cpmidx_double.o: cpmidx_double.c include/cpmidx_double.h
	      $(COMPILER) $(GCCFLAGS) -c cpmidx_double.c -c

cpmidx_float.o: cpmidx_float.c include/cpmidx_float.h
	      $(COMPILER) $(GCCFLAGS) -c cpmidx_float.c -c

loadmatrix.o: loadmatrix.c include/loadmatrix.h
	      $(COMPILER) $(GCCFLAGS) -c loadmatrix.c -c

loadmatrix_singleprec.o: loadmatrix_singleprec.c include/loadmatrix_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c loadmatrix_singleprec.c -c

nmfdriver.o: nmfdriver.c include/nmfdriver.h
	      $(COMPILER) $(GCCFLAGS) -c nmfdriver.c -c

nmfdriver_singleprec.o: nmfdriver_singleprec.c include/nmfdriver_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c nmfdriver_singleprec.c -c

nmf_pg.o: nmf_pg.c include/nmf_pg.h
	      $(COMPILER) $(GCCFLAGS) -c nmf_pg.c -c

nmf_pg_singleprec.o: nmf_pg_singleprec.c include/nmf_pg_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c nmf_pg_singleprec.c -c

nmf_fast.o: nmf_fast.c include/nmf_fast.h
		$(COMPILER) $(GCCFLAGS) -c nmf_fast.c -c

nmf_fast_singleprec.o: nmf_fast_singleprec.c include/nmf_fast_singleprec.h
		$(COMPILER) $(GCCFLAGS) -c nmf_fast_singleprec.c -c

nmf_bayes.o: nmf_bayes.c include/nmf_bayes.h
		$(COMPILER) $(GCCFLAGS) -c nmf_bayes.c -c

nmf_bayes_singleprec.o: nmf_bayes_singleprec.c include/nmf_bayes_singleprec.h
		$(COMPILER) $(GCCFLAGS) -c nmf_bayes_singleprec.c -c

randnumber.o: randnumber.c include/randnumber.h
	      $(COMPILER) $(GCCFLAGS) -c randnumber.c -c

randnumber_singleprec.o: randnumber_singleprec.c include/randnumber_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c randnumber_singleprec.c -c

calculatemaxchange.o:	calculatemaxchange.c include/calculatemaxchange.h
	      $(COMPILER) $(GCCFLAGS) -c calculatemaxchange.c -c

calculatemaxchange_singleprec.o: calculatemaxchange_singleprec.c include/calculatemaxchange_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c calculatemaxchange_singleprec.c -c

checkmatrices.o: checkmatrices.c include/checkmatrices.h
	      $(COMPILER) $(GCCFLAGS) -c checkmatrices.c -c

checkmatrices_singleprec.o: checkmatrices_singleprec.c include/checkmatrices_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c checkmatrices_singleprec.c -c

nmf_als.o: nmf_als.c include/nmf_als.h
	      $(COMPILER) $(GCCFLAGS) -c nmf_als.c -c

nmf_als_singleprec.o: nmf_als_singleprec.c include/nmf_als_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c nmf_als_singleprec.c -c

nmf_mu.o: nmf_mu.c include/nmf_mu.h
	      $(COMPILER) $(GCCFLAGS) -c nmf_mu.c -c

nmf_mu_singleprec.o: nmf_mu_singleprec.c include/nmf_mu_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c nmf_mu_singleprec.c -c

outputtiming.o: outputtiming.c include/outputtiming.h
	      $(COMPILER) $(GCCFLAGS) -c outputtiming.c -c

setdefaultopts.o: setdefaultopts.c include/setdefaultopts.h
	      $(COMPILER) $(GCCFLAGS) -c setdefaultopts.c -c

setdefaultopts_singleprec.o: setdefaultopts_singleprec.c include/setdefaultopts_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c setdefaultopts_singleprec.c -c

calculatenorm.o: calculatenorm.c include/calculatenorm.h
	      $(COMPILER) $(GCCFLAGS) -c calculatenorm.c -c

calculatenorm_singleprec.o: calculatenorm_singleprec.c include/calculatenorm_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c calculatenorm_singleprec.c -c

common.o: common.c include/common.h
	      $(COMPILER) $(GCCFLAGS) -c common.c -c

generatematrix.o: generatematrix.c include/generatematrix.h
	      $(COMPILER) $(GCCFLAGS) -c generatematrix.c -c

generatematrix_singleprec.o: generatematrix_singleprec.c include/generatematrix_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c generatematrix_singleprec.c -c

nmf_alspg.o: nmf_alspg.c include/nmf_alspg.h
	      $(COMPILER) $(GCCFLAGS) -c nmf_alspg.c -c

nmf_alspg_singleprec.o: nmf_alspg_singleprec.c include/nmf_alspg_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c nmf_alspg_singleprec.c -c

nmf_neals.o: nmf_neals.c include/nmf_neals.h
	      $(COMPILER) $(GCCFLAGS) -c nmf_neals.c -c

nmf_neals_singleprec.o: nmf_neals_singleprec.c include/nmf_neals_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c nmf_neals_singleprec.c -c

pg_subprob_h.o: pg_subprob_h.c include/pg_subprob_h.h
	      $(COMPILER) $(GCCFLAGS) -c pg_subprob_h.c -c

pg_subprob_h_singleprec.o: pg_subprob_h_singleprec.c include/pg_subprob_h_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c pg_subprob_h_singleprec.c -c

pg_subprob_w.o: pg_subprob_w.c include/pg_subprob_w.h
	      $(COMPILER) $(GCCFLAGS) -c pg_subprob_w.c -c

pg_subprob_w_singleprec.o: pg_subprob_w_singleprec.c include/pg_subprob_w_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c pg_subprob_w_singleprec.c -c

storematrix.o: storematrix.c include/storematrix.h
	      $(COMPILER) $(GCCFLAGS) -c storematrix.c -c

storematrix_singleprec.o: storematrix_singleprec.c include/storematrix_singleprec.h
	      $(COMPILER) $(GCCFLAGS) -c storematrix_singleprec.c -c

infogain.o: infogain.c include/infogain.h
		$(COMPILER) $(GCCFLAGS) -c infogain.c -c

infogain_singleprec.o: infogain_singleprec.c include/infogain_singleprec.h
		$(COMPILER) $(GCCFLAGS) -c infogain_singleprec.c -c

infogain_openmp.o: infogain_openmp.c include/infogain_openmp.h
		$(COMPILER) $(GCCFLAGS) -c infogain_openmp.c -c

infogain_openmp_singleprec.o: infogain_openmp_singleprec.c include/infogain_openmp_singleprec.h
		$(COMPILER) $(GCCFLAGS) -c infogain_openmp_singleprec.c -c

getentropy.o: getentropy.c include/getentropy.h
		$(COMPILER) $(GCCFLAGS) -c getentropy.c -c

getentropy_singleprec.o: getentropy_singleprec.c include/getentropy_singleprec.h
		$(COMPILER) $(GCCFLAGS) -c getentropy_singleprec.c -c

getinfogainforattribute.o: getinfogainforattribute.c include/getinfogainforattribute.h
		$(COMPILER) $(GCCFLAGS) -c getinfogainforattribute.c -c

getinfogainforattribute_singleprec.o: getinfogainforattribute_singleprec.c include/getinfogainforattribute_singleprec.h
		$(COMPILER) $(GCCFLAGS) -c getinfogainforattribute_singleprec.c -c


getattrvalvsclassoccurence.o: getattrvalvsclassoccurence.c include/getattrvalvsclassoccurence.h
		$(COMPILER) $(GCCFLAGS) -c getattrvalvsclassoccurence.c -c

getattrvalvsclassoccurence_singleprec.o: getattrvalvsclassoccurence_singleprec.c include/getattrvalvsclassoccurence_singleprec.h
		$(COMPILER) $(GCCFLAGS) -c getattrvalvsclassoccurence_singleprec.c -c




clean:
	rm -f $(LIBFOLDER)/libnnmf.so $(LIBFOLDER)/libnnmf.a blaslapack.o   cpmidx_double.o   cpmidx_float.o    checkarguments.o checkarguments_singleprec.o loadmatrix.o loadmatrix_singleprec.o nmfdriver.o nmfdriver_singleprec.o nmf_pg.o nmf_pg_singleprec.o nmf_fast.o   nmf_fast_singleprec.o    randnumber.o randnumber_singleprec.o \
	calculatemaxchange.o calculatemaxchange_singleprec.o checkmatrices.o checkmatrices_singleprec.o  nmf_als.o  nmf_als_singleprec.o   nmf_mu.o  nmf_mu_singleprec.o   outputtiming.o  setdefaultopts.o setdefaultopts_singleprec.o \
	calculatenorm.o getinfogain.o getentropy.o getinfogainforattribute.o getattrvalvsclassoccurence.o getinfogain_singleprec.o getentropy_singleprec.o getinfogainforattribute_singleprec.o getattrvalvsclassoccurence_singleprec.o calculatenorm_singleprec.o    common.o     generatematrix.o generatematrix_singleprec.o nmf_alspg.o nmf_alspg_singleprec.o  nmf_neals.o nmf_neals_singleprec.o pg_subprob_h.o pg_subprob_h_singleprec.o  pg_subprob_w.o  pg_subprob_w_singleprec.o storematrix.o storematrix_singleprec.o \
	calculatesvd.o calculatesvd_singleprec.o nmf_bayes.o nmf_bayes_singleprec.o infogain.o infogain_openmp.o infogain_singleprec.o infogain_openmp_singleprec.o