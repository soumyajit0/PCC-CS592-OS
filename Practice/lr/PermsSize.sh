#!/bin/bash
ls -l | tail -n +2 | tr -s " " | cut -d " " -f1,5 | cut -c2-
