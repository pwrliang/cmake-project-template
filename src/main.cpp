#include <division.h>
#include <iostream>

#include <gflags/gflags.h>
#include <gflags/gflags_declare.h>
#include <glog/logging.h>
#include "flags.h"

using namespace std;

static const char *const HEADER = "\nDivider © 2018 Monkey Claps Inc.\n\n";
static const char *const USAGE = "Usage:\n\tdivider <numerator> <denominator>\n\nDescription:\n\tComputes the result of a fractional division,\n\tand reports both the result and the remainder.\n";

int main(int argc, char *argv[]) {
    FLAGS_stderrthreshold = 0;

    gflags::SetUsageMessage(
            "Usage: mpiexec [mpi_opts] ./main [main_opts]");
    if (argc == 1) {
        gflags::ShowUsageWithFlagsRestrict(argv[0], "main");
        exit(1);
    }
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    gflags::ShutDownCommandLineFlags();

    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();


    Fraction f;

    cout << HEADER;

    // ensure the correct number of parameters are used.
    if (argc < 3) {
        cout << USAGE;
        return 1;
    }

    f.numerator = FLAGS_numerator;
    f.denominator = FLAGS_denominator;

    Division d = Division(f);
    try {
        DivisionResult r = d.divide();

        cout << "Division : " << f.numerator << " / " << f.denominator << " = " << r.division << "\n";
        cout << "Remainder: " << f.numerator << " % " << f.denominator << " = " << r.remainder << "\n";
    } catch (DivisionByZero) {
        cout << "Can not divide by zero, Homer. Sober up!\n";
    }
    google::ShutdownGoogleLogging();
    return 0;
}
