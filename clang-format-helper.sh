#!/bin/bash
fd "\.[hc]pp" | xargs clang-format -i
