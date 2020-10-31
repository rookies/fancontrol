#!/usr/bin/env python3
import matplotlib
from matplotlib import pyplot

matplotlib.rcParams['savefig.bbox'] = 'tight'
matplotlib.rcParams['savefig.pad_inches'] = .05
matplotlib.rcParams['font.family'] = 'serif'

pyplot.figure(figsize=matplotlib.figure.figaspect(.5))
pyplot.plot([0, .5, .5, 2, 2, 3, 4], [1, 1, 0, 0, .2, 1, 1])
pyplot.xticks([.5, 2, 3], ['errTemp', 'minTemp', 'maxTemp'])
pyplot.yticks([0, .2, 1], ['0', 'minPWM', 'maxPWM'])
pyplot.title('Influence of the temperature on the fan PWM value')
pyplot.xlabel('temperature')
pyplot.ylabel('fan PWM value')
pyplot.savefig('temperature_pwm.svg')
