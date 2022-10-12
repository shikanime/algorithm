.PHONY: all
all: setup

.PHONY: setup
setup: vcpkg/vcpkg.disable-metrics

vcpkg/vcpkg.disable-metrics:
	sh vcpkg/bootstrap-vcpkg.sh -disableMetrics
