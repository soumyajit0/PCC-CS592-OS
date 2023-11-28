#!/bin/bash
ls -l | tail -n +2 | tr -s " " | sort -t " " -k6,7
