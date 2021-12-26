#include <stdlib.h>
#include <argp.h>
<<<<<<< HEAD
#include <curl/curl.h>
#include <string.h>
#include <math.h>

// CONSTANTS

char *BEACH_FOLDER = "./BEACH";

// CURL write_data

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

// libcurl progressbar

int progress_func(void *ptr, double TotalToDownload, double NowDownloaded,
                  double TotalToUpload, double NowUploaded)
{
    // ensure that the file to be downloaded is not empty
    // because that would cause a division by zero error later on
    if (TotalToDownload <= 0.0)
    {
        return 0;
    }

    // how wide you want the progress meter to be
    int totaldotz = 40;
    double fractiondownloaded = NowDownloaded / TotalToDownload;
    // part of the progressmeter that's already "full"
    int dotz = (int)round(fractiondownloaded * totaldotz);

    // create the "meter"
    int ii = 0;
    printf("%3.0f%% [", fractiondownloaded * 100);
    // part  that's full already
    for (; ii < dotz; ii++)
    {
        printf("=");
    }
    // remaining part (spaces)
    for (; ii < totaldotz; ii++)
    {
        printf(" ");
    }
    // and back to line begin - do not forget the fflush to avoid output buffering problems!
    printf("]\r");
    fflush(stdout);
    // if you don't return 0, the transfer will be aborted - see the documentation
    return 0;
}

// ARGP
=======
>>>>>>> 85433a94da06581740b388c2f416ce1383dea164

const char *argp_program_version =
    "beach pre-0.0.1";
const char *argp_program_bug_address =
    "<https://github.com/SirObby/beachmaster/issues>";

/* Program documentation. */
static char doc[] =
    "Beach - Package Manager for Beachmaster";

/* A description of the arguments we accept. */
static char args_doc[] = "[COMMAND] PACKAGE...";

/* The options we understand. */
static struct argp_option options[] = {
    //    {"verbose", 'v', 0, 0, "Produce verbose output"},
    {"search", 'd', 0, OPTION_DOC, "What package to search.", 0},
    {"quiet", 'q', 0, 0, "Don't produce any output", 1},
    {"silent", 's', 0, OPTION_ALIAS, "", 1},
    {"deps", 'd', "DEPS", 0, "What dependencies to use. Separate with comma.", 1},
    {0}};

/* Used by main to communicate with parse_opt. */
struct arguments
{
    char *args[2]; /* arg1 & arg2 */
    int silent, verbose;
    char *output_file;
};

/* Parse a single option. */
static error_t
parse_opt(int key, char *arg, struct argp_state *state)
{
    /* Get the input argument from argp_parse, which we
     know is a pointer to our arguments structure. */
    struct arguments *arguments = state->input;

    switch (key)
    {
    case 'q':
    case 's':
        arguments->silent = 1;
        break;
    case 'v':
        arguments->verbose = 1;
        break;
    case 'o':
        arguments->output_file = arg;
        break;

    case ARGP_KEY_ARG:
        //if (state->arg_num >= 2)
<<<<<<< HEAD
        /* Too many arguments. */
        //argp_usage(state);
=======
            /* Too many arguments. */
            //argp_usage(state);
>>>>>>> 85433a94da06581740b388c2f416ce1383dea164

        arguments->args[state->arg_num] = arg;

        break;

    case ARGP_KEY_END:
        if (state->arg_num < 1)
            /* Not enough arguments. */
            argp_usage(state);
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}
/* Our argp parser. */
static struct argp argp = {options, parse_opt, args_doc, doc};

<<<<<<< HEAD
// Main function

=======
>>>>>>> 85433a94da06581740b388c2f416ce1383dea164
int main(int argc, char **argv)
{
    struct arguments arguments;

    /* Default values. */
    arguments.silent = 0;
    arguments.verbose = 0;
    arguments.output_file = "-";

    /* Parse our arguments; every option seen by parse_opt will
     be reflected in arguments. */
    argp_parse(&argp, argc, argv,
               0,
               0, &arguments);

<<<<<<< HEAD
    if (strcmp(arguments.args[0], "update") == 0)
    {
        printf("Fetching... \n");

        CURL *curl;
        FILE *fp;
        CURLcode res;
        char *url = "http://107.152.39.191:8080/packages.csv.tar.gz";
        char outfilename[FILENAME_MAX];
        sprintf(outfilename, "%s/packages.csv.tar.gz", BEACH_FOLDER);
        curl = curl_easy_init();
        if (curl)
        {
            fp = fopen(outfilename, "wb");
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            // Internal CURL progressmeter must be disabled if we provide our own callback
            curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);
            // Install the callback function
            curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_func);
            res = curl_easy_perform(curl);
            /* always cleanup */
            curl_easy_cleanup(curl);
            fclose(fp);
            char c[99999] = "";
            sprintf(c, "cd %s && tar -xzf ./packages.csv.tar.gz", BEACH_FOLDER, BEACH_FOLDER);
            if (system(c) == 0)
                printf("\nFile downloaded successfully.\n");
        }
    }

=======
>>>>>>> 85433a94da06581740b388c2f416ce1383dea164
    exit(0);
}