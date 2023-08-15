import { GithubOutlined } from '@ant-design/icons';
import { DefaultFooter } from '@ant-design/pro-components';

const Footer: React.FC = () => {
  const defaultMessage = '财大帅小伙学习用站';
  const currentYear = new Date().getFullYear();
  return (
    <DefaultFooter
      copyright={`${currentYear} ${defaultMessage}`}
      links={[
        {
          key: 'BiliBili',
          title: 'BiliBili',
          href: 'https://space.bilibili.com/502316536',
          blankTarget: true,
        },
        {
          key: 'github',
          title: <><GithubOutlined />oooohcan</>,
          href: 'https://github.com/oooohcan',
          blankTarget: true,
        },
        {
          key: 'movie',
          title: '看个电影',
          href: 'https://www.voflix.com/',
          blankTarget: true,
        },
      ]}
    />
  );
};

export default Footer;
