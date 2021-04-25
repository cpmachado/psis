/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/*
 * lib ra is a library of random array functions
 *
 * Currently:
 * - random array generator
 * - print divisible numbers according to divisors
 */

#ifndef WEEK5_INCLUDE_LIBRA_H_
#define WEEK5_INCLUDE_LIBRA_H_

/* FUCTION DECLARATIONS */

/* randArrayULong:
 * Generate an array of a given length len
 * with random integers with a max of limit
 */
unsigned long* randArrayULong(unsigned long len, unsigned long limit);

/*
 * printDivisible:
 * print array elements according to divisors
 */
void printDivisible(unsigned long len, unsigned long *array);

#endif /* WEEK5_INCLUDE_LIBRA_H_ */
