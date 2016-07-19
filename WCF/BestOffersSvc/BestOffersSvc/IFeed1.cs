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
    [ServiceContract]

    public interface IFeed1
    {
        [OperationContract]
        [WebGet]
        Rss20FeedFormatter CreateFeed();
    }
}
