#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer10.h"

const char businesses_path[] = "/home/shay/a/ece264p0/share/yelp_data/businesses.tsv";
const char reviews_path[] = "/home/shay/a/ece264p0/share/yelp_data/reviews.tsv";
//const char businesses_path[] = "/home/shay/a/ece264p0/share/yelp_data/businesses.short.tsv";
//const char reviews_path[] = "/home/shay/a/ece264p0/share/yelp_data/reviews.short.tsv";

int main(int argc, char *argv[]) {

	// Check number of arguments.  Name of executable is always first argument.  name1 is required.
	if((argc + 2) / 3 == 0) {
		fprintf(stderr, "Usage:\n%s <name1> [state1] [zip1] [name2] [state2] [zip2] ...\n\n", argv[0]);
		return EXIT_FAILURE;
	}

	// Create instance of YelpDataBST
	struct YelpDataBST* bst = create_business_bst(businesses_path, reviews_path);

	// We will collect stats for easy summarization
	int num_locations=0, num_address_chars=0, num_reviews=0, num_review_chars=0, total_stars=0;

	int arg_idx;
	for(arg_idx = 1; arg_idx < argc; arg_idx += 3) {

		// Extract the query
		char* name     = argv[arg_idx];
		char* state    = arg_idx + 1 < argc ? argv[arg_idx + 1] : "";
		char* zip_code = arg_idx + 2 < argc ? argv[arg_idx + 2] : "";

		// Print the query
		int query_num = (arg_idx + 2) / 3;
		printf("================================================================================\n");
		printf("QUERY #%d:  name=\"%s\"  state=\"%s\"  zip_code=\"%s\"\n\n", query_num, name, state, zip_code);

		// If state or zip_code are "", change them to NULL.   (The specification of get_business_reviews(..)
		// says to pass NULL to include all states and zip codes.)
		char* state_or_null    = state[0]    == '\0' ? NULL : state;    // change to NULL if ""
		char* zip_code_or_null = zip_code[0] == '\0' ? NULL : zip_code; // change to NULL if ""
		struct Business *b = get_business_reviews(bst, name, state_or_null, zip_code_or_null);

		// Print results
		if(b == NULL) {
			printf("RESULTS:  (none)\n\n");
		}
		else {
			printf("RESULTS:  \"%s\"  (%d locations)\n\n", b->name, b->num_locations);

			int location_idx;
			for(location_idx=0; location_idx<b->num_locations; location_idx++) {

				// Print LOCATION
				struct Location loc = b->locations[location_idx];
				printf("LOCATION #%d:  address=\"%s\"  city=\"%s\"  state=\"%s\"  zip_code=\"%s\"  (%d reviews)\n\n",
					   location_idx + 1, loc.address, loc.city, loc.state, loc.zip_code, loc.num_reviews);
				num_address_chars += strlen(loc.address) + strlen(loc.state) + strlen(loc.zip_code);
				num_locations++;

				// Print REVIEW
				int review_idx;
				for(review_idx=0; review_idx<loc.num_reviews; review_idx++) {
					struct Review rvw = loc.reviews[review_idx];
					printf("REVIEW #%d:  %d stars  (%d chars)\n", review_idx + 1, rvw.stars, (int)strlen(rvw.text));
					printf("%s\n\n", rvw.text);
					num_reviews++;
					num_review_chars += strlen(rvw.text);
					total_stars += rvw.stars;
				}

				// Print a divider (unless this is the last time)
				if(location_idx + 1 < b->num_locations) {
					printf("................................................................................\n");
				}
			}
			printf("\n");

			// Destroy (free) the result object
			destroy_business_result(b);
		}
	}

	// Print summary
	float avg_stars = num_reviews > 0 ? 1.0 * total_stars / num_reviews : 0.0;
	printf("================================================================================\n");
	printf("SUMMARY:  %d locations (%d chars),  %d reviews (%d chars),  %.2f stars avg\n",
		num_locations, num_address_chars, num_reviews, num_review_chars, avg_stars);
	printf("================================================================================\n");

	// Destroy (free) the BST and 
	destroy_business_bst(bst);

	return EXIT_SUCCESS;
}






/* HOW TO COMPILE
 *
 * gcc -o search search.c answer10.c -Wall -Wshadow
 *
 *
 * USAGE EXAMPLES
 *
 * # One query, by name only
 * ./search Starbucks
 *
 * # One query, all details
 * ./search Starbucks AZ 12345
 *
 * # One query, name and state
 * ./search Starbucks AZ
 *
 * # One query, name and zip_code
 * ./search Starbucks "" 12345
 *
 * # Two queries, all details
 * ./search Starbucks AZ 12345 "Pete's Coffee" AZ 12345
 *
 * # Two queries, names only
 * ./search Starbucks "" "" "Pete's Coffee"
 *
 *
 * TIPS
 *
 * # Print only the summary
 * ./search Starbucks | tail -n3
 *
 * # Measure run time
 * time ./search Starbucks
 *
 * # Test with less data
 * time ./search Starbucks
 *
 */
