using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Syndication;
using System.ServiceModel.Web;
using System.Text;

namespace BestOffersSvc
{
    public class Feed1 : IFeed1
    {
        public Rss20FeedFormatter CreateFeed()
        {
            SyndicationFeed feed = new SyndicationFeed("Best Offers Feeds","Best of the Offers are availabe",new Uri("http://BestOfferSvc"));
            feed.Authors.Add(new SyndicationPerson("surenthar.selvaraj@wipro.com"));
            feed.Categories.Add(new SyndicationCategory("Festive offer and beyond"));
            feed.Description = new TextSyndicationContent("Already Mentioned");
            SyndicationItem item1 = new SyndicationItem("Arrows Shirts", "50% off", new Uri("http://arrowsshirts.com"), "any Size", DateTime.Now);
            SyndicationItem item2 = new SyndicationItem("Arrows T-Shirts", "40% off", new Uri("http://arrowsshirts.com"), "any Size", DateTime.Now);
            SyndicationItem item3 = new SyndicationItem("Arrows FormalShirts", "70% off", new Uri("http://arrowsshirts.com"), "any Size", DateTime.Now);

            List<SyndicationItem> items = new List<SyndicationItem>();
            items.Add(item1); items.Add(item2); items.Add(item3);

            feed.Items = items;
            return new Rss20FeedFormatter(feed);
        }
    }
}
