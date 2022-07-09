#!/usr/bin/env python3

import subprocess

SAMPLE_SIZES = [
    50,
    100,
    200,
    300,
    500,
    750,
    1_000,
    1_500,
    2_000,
    3_000,
    5_000,
    7_500,
    10_000,
    12_500,
    15_000,
    20_000,
    25_000,
    30_000,
    40_000,
    50_000,
    75_000,
    100_000,
    125_000,
    200_000,
    250_000
]

RUNS = str(11)

EXEC = './bin/release/t3'

for i, sample_size in enumerate(SAMPLE_SIZES):
    print('------------------------------------------------------------------------')
    print(f'Running sample [{i+1}/{len(SAMPLE_SIZES)}]')
    print('------------------------------------------------------------------------')

    build = f'data/Construir{sample_size}.txt'
    query = f'data/Consultar{sample_size}.txt'
    output = f'results/out_{sample_size}.csv'

    subprocess.run(args=[
        EXEC, build, query, "-r", RUNS, "-o", output
    ])

print('------------------------------------------------------------------------')
print('Done.')

