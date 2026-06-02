# EllipticCurveFiniteFieldExplorer
A C++ program for exploring elliptic curves over finite fields.

The program studies curves of the form

E: y^2 = x^3 + ax + b over F_p where p is a prime not equal to 2 or 3.

**Features**

The program currently:

asks the user to input a prime p and the coefficents a and b;
it checks whether p is prime;
rejects the cases p = 2 and p = 3 to be able to work with the Short Weierstrass form;
computes the discriminant modulo p;
determines whether the curve is nonsingular modulo p;
computes the number of points on E(F_p);
lists the set of affine points found on the curve.

**Mathematical background**
For each x in F_p, the program computes x^3 + ax + b mod p.
It then uses Euler's criterion to determine whether this value is a quadratic residue modulo p.
If the value is:
zero, then there is one corresponding point: (x, 0);
a nonzero square, then there are two corresponding points;
a nonsquare, then there are no corresponding points.

The point at infinity is included in the final count.

**Example**
For example, the user may study the curve
y^2 = x^3 + x + 3 over F_7.
The program computes the points over F_7 and returns #E(F_7).
We find that #E(F_7)= 6, where the points are:{(4, 1),  (4, 6),  (5, 0),  (6, 1),  (6, 6),  the point at infinity [0:1:0]}

**Future improvements**

Planned extensions include:

implementing the elliptic curve group law;
adding point addition and point doubling;
computing the order of a point;
testing Hasse's bound;
studying the same curve modulo several primes;
comparing point counts for different reductions.
