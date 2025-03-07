import importlib

import propagator

from z3 import Solver

s = Solver()

p = propagator.EmptyPropagator(s.solver)