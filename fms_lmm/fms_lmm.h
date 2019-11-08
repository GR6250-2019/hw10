// fms_lmm.h - LIBOR market model
/*
	The LIBOR market model has parameters, (t[j]), (f[j]), (sigma[j]), and alpha,
	where f[j] is the forward over (t[j-1], t[j]], sigma[j] is the corresponding
	at-the-money caplet implied volatility, and alpha is a correlation parameter 
	for two dimensional Brownian motion.

	The repo rates are F_j = phi[j] exp(sigma[j] B_{t_j} - sigma[j]^2 t[j]/2),
	where B_t = B0_t cos(alpha t) + B1_t sin(alpha t) and B0, B1 are independent
	Brownian motions.

	Define 

	Note if t < u,
	
	    Cov(B_t, B_u) = E[B0_t B0_u cos(alpha t) cos(alpha u) 
	                    + B0_t B1_u cos(alpha t) sin(alpha u)
					    + B1_t B0_u sin(alpha t) cos(alpha u)
						+ B1_t B1_u sin(alpha t) sin(alpha u)]
					  = t [cos(alpha t) cos(alpha u) + sin(alpha t) sin(alpha u)
					  = t cos(u - t).
*/
#pragma once

