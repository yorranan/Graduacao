import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl

setpoint = ctrl.Antecedent(np.arange(1, 7, .1), 'setpoint')
delta = ctrl.Antecedent(np.arange(-7, 7, .01), 'delta')
frequencia = ctrl.Consequent(np.arange(30, 60, 1), 'frequencia')

setpoint['mal'] = fuzz.trimf(setpoint.universe, [4.5, 5.5, 6.5])
setpoint['al'] = fuzz.trimf(setpoint.universe, [4, 4.5, 5.5])
setpoint['est'] = fuzz.trimf(setpoint.universe, [3.5, 4, 4.5])
setpoint['bx'] = fuzz.trimf(setpoint.universe, [2.5, 3.5, 3.8])
setpoint['mbx'] = fuzz.trimf(setpoint.universe, [2, 3, 3.5])

delta['mal'] = fuzz.trimf(delta.universe, [0.20, 1, 6.5])
delta['al'] = fuzz.trimf(delta.universe, [0.1, 0.20, 0.25])
delta['est'] = fuzz.trimf(delta.universe, [-0.15, 0, 0.15])
delta['bx'] = fuzz.trimf(delta.universe, [-.25, -.2, -.1])
delta['mbx'] = fuzz.trimf(delta.universe, [-6.5, -1, -.20])

frequencia['mal'] = fuzz.trimf(frequencia.universe, [50, 53, 55])
frequencia['al'] = fuzz.trimf(frequencia.universe, [46, 49, 51])
frequencia['est'] = fuzz.trimf(frequencia.universe, [42, 45, 47])
frequencia['bx'] = fuzz.trimf(frequencia.universe, [39, 41, 43])
frequencia['mbx'] = fuzz.trimf(frequencia.universe, [35, 38, 40])

setpoint.view()
delta.view()
frequencia.view()

regra1 = ctrl.Rule(antecedent=((setpoint['mbx'] & delta['mbx']) |
                              (setpoint['bx'] & delta['mbx']) |
                              (setpoint['mbx'] & delta['bx'])),
                  consequent=frequencia['mal'], label='rule nb')

regra2 = ctrl.Rule(antecedent=((setpoint['mbx'] & delta['est']) |
                              (setpoint['mbx'] & delta['al']) |
                              (setpoint['bx'] & delta['bx']) |
                              (setpoint['bx'] & delta['est']) |
                              (setpoint['est'] & delta['bx']) |
                              (setpoint['est'] & delta['mbx']) |
                              (setpoint['al'] & delta['mbx'])),
                  consequent=frequencia['al'], label='rule ns')

regra3 = ctrl.Rule(antecedent=((setpoint['mbx'] & delta['mal']) |
                              (setpoint['bx'] & delta['al']) |
                              (setpoint['est'] & delta['est']) |
                              (setpoint['al'] & delta['bx']) |
                              (setpoint['mal'] & delta['mbx'])),
                  consequent=frequencia['est'], label='rule ze')

regra4 = ctrl.Rule(antecedent=((setpoint['bx'] & delta['mal']) |
                              (setpoint['est'] & delta['mal']) |
                              (setpoint['est'] & delta['al']) |
                              (setpoint['al'] & delta['al']) |
                              (setpoint['al'] & delta['est']) |
                              (setpoint['mal'] & delta['est']) |
                              (setpoint['mal'] & delta['bx'])),
                  consequent=frequencia['bx'], label='rule ps')

regra5 = ctrl.Rule(antecedent=((setpoint['al'] & delta['mal']) |
                              (setpoint['mal'] & delta['mal']) |
                              (setpoint['mal'] & delta['al'])),
                  consequent=frequencia['mbx'], label='rule pb')

system = ctrl.ControlSystem(rules=[regra1, regra2, regra3, regra4, regra5])

simulador = ctrl.ControlSystemSimulation(system)
simulador0 = ctrl.ControlSystemSimulation(system)
simulador1 = ctrl.ControlSystemSimulation(system)

simulador.input['setpoint'] = 2.1
simulador.input['delta'] = -1.3

# sp baixo-normal e delta muito alto
simulador0.input['setpoint'] = 3.6
simulador0.input['delta'] = 6.0

# sp muito alto e delta muito baixo - baixo
simulador1.input['setpoint'] = 6.2
simulador1.input['delta'] = 2.6

simulador.compute()
print(simulador.output['frequencia'])

frequencia.view(sim=simulador)
setpoint.view(sim=simulador)
delta.view(sim=simulador)

simulador0.compute()
print(simulador0.output['frequencia'])

frequencia.view(sim=simulador0)
setpoint.view(sim=simulador0)
delta.view(sim=simulador0)

simulador1.compute()
print(simulador1.output['frequencia'])

frequencia.view(sim=simulador1)
setpoint.view(sim=simulador1)
delta.view(sim=simulador1)